import os
import subprocess
import sys

def run_command(command):
    try:
        subprocess.run(command, check=True, shell=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running command: {command}")
        print(f"Error message: {e}")
        sys.exit(1)

def create_batches(input_file, output_dir):
    # Check if the input file exists
    if not os.path.isfile(input_file):
        print(f"Error: Input file '{input_file}' not found.")
        sys.exit(1)

    # Create the output directory if it does not exist
    os.makedirs(output_dir, exist_ok=True)

    # Read data_array from the input file, extracting only "DATAFILE" lines
    data_array = []
    with open(input_file, 'r') as file:
        for line in file:
            if line.startswith("\t\"DATAFILE="):
                data_array.append(line.strip())

    batch_size = 100
    for i in range(0, len(data_array), batch_size):
        batch_data = data_array[i:i+batch_size]
        create_batch_file(output_dir, i//batch_size, batch_data)

def create_batch_file(output_dir, batch_num, batch_data):
    file_content = f"from Configurables import DaVinci\n\nDaVinci().Input += [\n"
    for item in batch_data:
        file_content += f"\t{item},\n"
    file_content += "]\n"

    filename = os.path.join(output_dir, f"batch_{batch_num}.py")
    with open(filename, 'w') as file:
        file.write(file_content)

def run_batches(batch_dir):
    for filename in os.listdir(batch_dir):
        if filename.startswith("batch_") and filename.endswith(".py"):
            batch_file_path = os.path.join(batch_dir, filename)

            command = f"lb-run Davinci/v45r8 gaudirun.py Z_data_to_root.py {batch_file_path}"
            run_command(command)

            # Edit fetch_Zmumu.py after running the batch
            edit_fetch_Zmumu(filename)

def edit_fetch_Zmumu(batch_file_name):
    with open("fetch_Zmumu.py", 'r') as file:
        lines = file.readlines()

    # Find and replace the lines with the tuplefilename
    for i in range(len(lines)):
        if "DaVinci().HistogramFile" in lines[i]:
            lines[i] = f"DaVinci().HistogramFile = '{os.path.splitext(batch_file_name)[0]}_histos.root'\n"
        elif "DaVinci().TupleFile" in lines[i]:
            lines[i] = f"DaVinci().TupleFile = '{os.path.splitext(batch_file_name)[0]}.root'\n"

    # Write back to fetch_Zmumu.py
    with open("fetch_Zmumu.py", 'w') as file:
        file.writelines(lines)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python fetch_in_batches.py <input_file_name>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_dir = os.path.splitext(input_file)[0]  # Remove extension from input file name

    create_batches(input_file, output_dir)
    run_batches(output_dir)

    print("Batch files executed successfully.")
