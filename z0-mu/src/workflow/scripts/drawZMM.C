#define GraphingManager_cxx

#include "GraphingManager.h"

inline const char HISTOGRAM_INVARIANT_MASS_SIMPLE_Z[] = "InvariantMassZ";

void drawZMM(const string inputFileName, int nbins, double from, double to, const char* outputFileName) {
    // ======================================================
    // READ TREE
    // ------------------------------------------------------
    TTree* inputTree;

    std::string directoryName = "Tuple";
    std::string treeName = "DecayTree";

    auto inputFile = TFile::Open(inputFileName.c_str(), "READ");
    if (!inputFile || inputFile->IsZombie()) {
        std::cerr << "Error: Could not open file " << inputFileName << std::endl;
        return;
    }

    inputTree = inputFile->Get<TTree>("DecayTreeAfterCutflow");

    if (!inputTree) {
        std::cerr << "Error: Could not find TTree in file " << inputFileName << std::endl;
        return;
    } 

    // ======================================================
    // CREATE AND SAVE HISTOGRAM TO FILE
    // ------------------------------------------------------
    auto graphingManager = new GraphingManager();

    graphingManager->LoadConfig({
        {
            "canvas_invariant_mass",
            "Z Boson Invariant Mass Distribution",
            outputFileName,
            {
                {HISTOGRAM_INVARIANT_MASS_SIMPLE_Z, "Simple energy calculation", 100, 35000, 140000, kBlue},
            },
            {"Invariant_Mass_Stack", "Z Boson Invariant Mass Distribution", "Invariant Mass (MeV/c^2)", "Frequency"}
        },
    });

    graphingManager->CreateHistograms();

    // Fill in the histogram
    Double_t Z_MM;
    inputTree->SetBranchAddress("Z_MM", &Z_MM);

    int nEntries = inputTree->GetEntries();
    for (int i = 0; i < nEntries; i++) {
        inputTree->GetEntry(i);

        graphingManager->FillHistogram(HISTOGRAM_INVARIANT_MASS_SIMPLE_Z, Z_MM);
    }

    graphingManager->Print();

    // Clean up
    inputFile->Close();
}