#define GraphingManager_cxx
#define ZDecayAnalyser_cxx

#include "GraphingManager.h"
#include "HistogramConfig.h"
#include "ZDecayAnalyser.h"
#include <TCanvas.h>
#include <TH2.h>
#include <TStyle.h>

#include <TH1.h>
#include <TMath.h>

inline const char HISTOGRAM_LEADING_PT[] = "LeadingPT";
inline const char HISTOGRAM_SUBLEADING_PT[] = "SubleadingPT";

inline const char HISTOGRAM_INVARIANT_MASS_TLORENTZ[] = "InvariantMassTLorentz";
inline const char HISTOGRAM_INVARIANT_MASS_SIMPLE[] = "InvariantMassSimple";

inline const char HISTOGRAM_LEADING_PROBNNMU[] = "LeadingProbNNmu";
inline const char HISTOGRAM_SUBLEADING_PROBNNMU[] = "SubleadingProbNNmu";

inline const char HISTOGRAM_LEADING_RAPIDITY[] = "LeadingRapidity";
inline const char HISTOGRAM_SUBLEADING_RAPIDITY[] = "SubleadingRapidity";

inline const char HISTOGRAM_SUM_PT[] = "SumPT";
inline const char HISTOGRAM_Z_PT[] = "ZPT";

inline const char HISTOGRAM_SUM_RAPIDITY[] = "SumRapidity";

GraphingManager graphingManager;

Double_t CalculateInvariantMassSimple(TLorentzVector muon1,
                                      TLorentzVector muon2) {
  auto E1 = TMath::Sqrt(muon1.M() * muon1.M() + muon1.Px() * muon1.Px() +
                        muon1.Py() * muon1.Py() + muon1.Pz() * muon1.Pz());
  auto E2 = TMath::Sqrt(muon2.M() * muon2.M() + muon2.Px() * muon2.Px() +
                        muon2.Py() * muon2.Py() + muon2.Pz() * muon2.Pz());

  auto PX = muon1.Px() + muon2.Px();
  auto PY = muon1.Py() + muon2.Py();
  auto PZ = muon1.Pz() + muon2.Pz();

  return TMath::Sqrt((E1 + E2) * (E1 + E2) - PX * PX - PY * PY - PZ * PZ);
}

void ZDecayAnalyser::ProcessFill() {
  Double_t leading_PT = TMath::Max(this->muon1_PT, this->muon2_PT);
  Double_t subleading_PT = TMath::Min(this->muon1_PT, this->muon2_PT);

  TLorentzVector muon1(this->muon1_PX, this->muon1_PY, this->muon1_PZ,
                       TMath::Sqrt(this->muon1_M * this->muon1_M +
                                   this->muon1_PX * this->muon1_PX +
                                   this->muon1_PY * this->muon1_PY +
                                   this->muon1_PZ * this->muon1_PZ));
  TLorentzVector muon2(this->muon2_PX, this->muon2_PY, this->muon2_PZ,
                       TMath::Sqrt(this->muon2_M * this->muon2_M +
                                   this->muon2_PX * this->muon2_PX +
                                   this->muon2_PY * this->muon2_PY +
                                   this->muon2_PZ * this->muon2_PZ));
  TLorentzVector total = muon1 + muon2;

  Double_t leading_ProbNNmu = this->muon1_ProbNNmu;
  Double_t subleading_ProbNNmu = this->muon2_ProbNNmu;

  Double_t leading_rapidity = muon1.Rapidity();
  Double_t subleading_rapidity = muon2.Rapidity();

  if (this->muon1_PT < this->muon2_PT) {
    leading_ProbNNmu = this->muon2_ProbNNmu;
    subleading_ProbNNmu = this->muon1_ProbNNmu;

    leading_rapidity = muon2.Rapidity();
    subleading_rapidity = muon1.Rapidity();
  }

  // PT
  graphingManager.histogramDictionary[HISTOGRAM_LEADING_PT]->Fill(leading_PT);
  graphingManager.histogramDictionary[HISTOGRAM_SUBLEADING_PT]->Fill(
      subleading_PT);

  // Invariant Mass
  graphingManager.histogramDictionary[HISTOGRAM_INVARIANT_MASS_TLORENTZ]->Fill(
      total.M());
  graphingManager.histogramDictionary[HISTOGRAM_INVARIANT_MASS_SIMPLE]->Fill(
      CalculateInvariantMassSimple(muon1, muon2));

  // ProbNNmu
  graphingManager.histogramDictionary[HISTOGRAM_LEADING_PROBNNMU]->Fill(
      leading_ProbNNmu);
  graphingManager.histogramDictionary[HISTOGRAM_SUBLEADING_PROBNNMU]->Fill(
      subleading_ProbNNmu);

  // Rapidity
  graphingManager.histogramDictionary[HISTOGRAM_LEADING_RAPIDITY]->Fill(
      leading_rapidity);
  graphingManager.histogramDictionary[HISTOGRAM_SUBLEADING_RAPIDITY]->Fill(
      subleading_rapidity);

  // Sum PT
  graphingManager.histogramDictionary[HISTOGRAM_SUM_PT]->Fill(total.Pt());
  graphingManager.histogramDictionary[HISTOGRAM_Z_PT]->Fill(this->Z_PT);

  // Sum Rapidity
  graphingManager.histogramDictionary[HISTOGRAM_SUM_RAPIDITY]->Fill(
      total.Rapidity());
}

void ZDecayAnalyser::Loop() {
  if (fChain == 0)
    return;

  Long64_t nentries = fChain->GetEntriesFast();

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry = 0; jentry < nentries; jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0)
      break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;
    if (Cut(ientry) < 0)
      continue;

    this->ProcessFill();
  }
}

void ZDecayAnalyser::Process() {
  graphingManager->LoadConfig({
      {"canvas_muon_pt",
       "Leading and Subleading Muon PT",
       "../analysis/visuals/root/muon-pt-distribution.png",
       {{HISTOGRAM_LEADING_PT, "Leading Muon PT", 100, 8000, 130000, kGreen},
        {HISTOGRAM_SUBLEADING_PT, "Subleading Muon PT", 100, 0, 130000, kRed}},
       {"PT_Stack", "Muon PT Distribution", "PT", "Frequency"}},
      {"canvas_invariant_mass",
       "Invariant Mass Distribution (Calculation Comparison)",
       "../analysis/visuals/root/z-invariant-mass-distribution.png",
       {
           {HISTOGRAM_INVARIANT_MASS_TLORENTZ, "TLorentz vector", 100, 35000,
            140000, kGreen},
           {HISTOGRAM_INVARIANT_MASS_SIMPLE, "Simple energy calculation", 100,
            35000, 140000, kBlue},
       },
       {"Invariant_Mass_Stack", "Invariant Mass Distribution",
        "Invariant Mass (MeV/c^2)", "Frequency"}},
      {"canvas_ProbNNmu",
       "Muon Bayesian Posteriori Probability Distribution",
       "../analysis/visuals/root/muon1-muon2-ProbNNmu-distribution.png",
       {
           {HISTOGRAM_LEADING_PROBNNMU, "ProbNNmu Leading", 100, 0, 1, kGreen},
           {HISTOGRAM_SUBLEADING_PROBNNMU, "ProbNNmu Subleading", 100, 0, 1,
            kBlue},
       },
       {"ProbNNmu_stack", "Muon Bayesian Posteriori Probability Distribution",
        "ProbNNmu", "Frequency"}},
      {"canvas_rapidity",
       "Muon Rapidity Distribution",
       "../analysis/visuals/root/muon-rapidity-distribution.png",
       {
           {HISTOGRAM_LEADING_RAPIDITY, "Rapidity Leading", 100, 1, 5.5,
            kGreen},
           {HISTOGRAM_SUBLEADING_RAPIDITY, "Rapidity Subleading", 100, 1, 5.5,
            kBlue},
       },
       {"Rapidity_stack", "Muon Rapidity Distribution", "Rapidity",
        "Frequency"}},
      {"canvas_sum_PT",
       "Lepton Sum PT Distribution",
       "../analysis/visuals/root/muon-sum-pt-distribution.png",
       {
           {HISTOGRAM_SUM_PT, "Sum PT", 100, -1000, 120000, kGreen},
           {HISTOGRAM_Z_PT, "Z PT", 100, -1000, 120000, kBlue},
       },
       {"Sum_PT_stack", "Lepton Sum PT", "PT", "Frequency"}},
      {"canvas_sum_Rapidity",
       "Lepton Sum Rapidity Distribution",
       "../analysis/visuals/root/muon-sum-rapidity-distribution.png",
       {
           {HISTOGRAM_SUM_RAPIDITY, "Sum Rapidity", 100, 1, 5.5, kGreen},
       },
       {"Sum_Rapidity_stack", "Lepton Sum Rapidity", "Rapidity", "Frequency"}},
  });
  graphingManager.CreateHistograms();

  this->Loop();
  graphingManager.Draw();
}
