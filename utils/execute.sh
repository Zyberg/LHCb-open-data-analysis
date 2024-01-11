#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 /path/to/your/directory"
    exit 1
fi

DIRECTORY="$1"

# Check if the directory exists
if [ ! -d "$DIRECTORY" ]; then
    echo "Error: Directory $DIRECTORY not found."
    exit 1
fi

# Define the template content for the Python script
TEMPLATE="from Configurables import DaVinci\nDaVinci().HistogramFile = 'batch_%s_histos.root'\nDaVinci().TupleFile = 'batch_%s.root'"

# Loop through each file in the directory
for FILENAME in "$DIRECTORY"/*; do
    # Get the base name of the file (without the path)
    BASENAME=$(basename "$FILENAME")

    # Create the Python script with the template content
    printf "$TEMPLATE" "$BASENAME" > run_batch.py

    # Run your command using the created Python script
    lb-run Davinci/v45r8 gaudirun.py fetch_Zmumu.py run_batch.py "$FILENAME"

    # Optionally, remove the created Python script if not needed
    # rm run_batch.py
done
