#include <TFile.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include <iostream>
#include <string>

using namespace std;

inline const char NAMECYCLE[] = "DecayTreeAfterCutflow";

void appendTLorentz(const string inputFileName, const char *outputFileName) {
  // ======================================================
  // READ TREE
  // ------------------------------------------------------
  auto inputFile = new TFile(inputFileName.c_str(), "READ");
  if (!inputFile || inputFile->IsZombie()) {
    std::cerr << "Error: Could not open file " << inputFileName << std::endl;
    return;
  }

  auto tree = (TTree *)inputFile->Get(NAMECYCLE);

  if (!tree) {
    std::cerr << "Error: Could not find TTree in file " << inputFileName
              << std::endl;
    return;
  }

  // ======================================================
  // Append TLorenz Vector Branch
  // ------------------------------------------------------
  // Create the output file
  TFile *outputFile = new TFile(outputFileName, "RECREATE");

  // Clone the input tree
  TTree *outputTree = tree->CloneTree(0);

  // Create TLorentzVector and fill its branch
  TLorentzVector muon1_LorentzVector, muon2_LorentzVector, muon_sum_LorentzVector;
  outputTree->Branch("muon1_LorentzVector", &muon1_LorentzVector);
  outputTree->Branch("muon2_LorentzVector", &muon2_LorentzVector);
  outputTree->Branch("muon_sum_LorentzVector", &muon_sum_LorentzVector);

  Double_t muon1_P, muon1_PX, muon1_PY, muon1_PZ, muon1_M, 
           muon2_P, muon2_PX, muon2_PY, muon2_PZ, muon2_M;
  tree->SetBranchAddress("muon1_P", &muon1_P);
  tree->SetBranchAddress("muon1_PX", &muon1_PX);
  tree->SetBranchAddress("muon1_PY", &muon1_PY);
  tree->SetBranchAddress("muon1_PZ", &muon1_PZ);
  tree->SetBranchAddress("muon1_M", &muon1_M);
  tree->SetBranchAddress("muon2_P", &muon2_P);
  tree->SetBranchAddress("muon2_PX", &muon2_PX);
  tree->SetBranchAddress("muon2_PY", &muon2_PY);
  tree->SetBranchAddress("muon2_PZ", &muon2_PZ);
  tree->SetBranchAddress("muon2_M", &muon2_M);

  int nEntries = tree->GetEntries();
  for (int i = 0; i < nEntries; i++) {
    tree->GetEntry(i);

    // Fill Lorentz Vectors
    muon1_LorentzVector.SetPxPyPzE(muon1_PX, muon1_PY, muon1_PZ, TMath::Sqrt(muon1_P * muon1_P + muon1_M * muon1_M));
    muon2_LorentzVector.SetPxPyPzE(muon2_PX, muon2_PY, muon2_PZ, TMath::Sqrt(muon2_P * muon2_P + muon2_M * muon2_M));
    muon_sum_LorentzVector = muon1_LorentzVector + muon2_LorentzVector;

    outputTree->Fill();
  }

  // Write the output tree to the output file
  outputFile->cd();
  outputTree->SetName("DecayTreeAfterProcessing");
  outputTree->Write();

  // Clean up
  outputFile->Close();
  inputFile->Close();
}