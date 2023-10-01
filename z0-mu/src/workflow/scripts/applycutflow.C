void applycutflow(const string inputFileName, double pTThreshold,
                  const char *outputFileName) {
  // ======================================================
  // READ TREE
  // ------------------------------------------------------
  TTree *inputTree;

  std::string directoryName = "Tuple";
  std::string treeName = "DecayTree";

  auto inputFile = TFile::Open(inputFileName.c_str(), "READ");
  if (!inputFile || inputFile->IsZombie()) {
    std::cerr << "Error: Could not open file " << inputFileName << std::endl;
    return;
  }

  TDirectory *dir = inputFile->GetDirectory(directoryName.c_str());

  inputTree = dir->Get<TTree>("DecayTree");

  if (!inputTree) {
    std::cerr << "Error: Could not find TTree in file " << inputFileName
              << std::endl;
    return;
  }

  // ======================================================
  // Process the Cutflows
  // ------------------------------------------------------
  // Create the output file
  TFile *outputFile = new TFile(outputFileName, "RECREATE");

  // Clone the input tree
  TTree *outputTree = inputTree->CloneTree(0);

  // Apply cutflow based on pT threshold
  Double_t muon1_PT, muon2_PT;
  inputTree->SetBranchAddress("muon1_PT", &muon1_PT);
  inputTree->SetBranchAddress("muon2_PT", &muon2_PT);

  int nEntries = inputTree->GetEntries();
  for (int i = 0; i < nEntries; i++) {
    inputTree->GetEntry(i);

    // PT cut
    if (muon1_PT >= pTThreshold && muon2_PT >= pTThreshold)
      outputTree->Fill();
  }

  // Write the output tree to the output file
  outputFile->cd();
  outputTree->SetName("DecayTreeAfterCutflow");
  outputTree->Write();

  // Clean up
  outputFile->Close();
  inputFile->Close();
}