#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <TH1F.h>
#include <TMath.h>
#include <TLegend.h>

#include <TBranch.h>
#include <TObjArray.h>

struct BranchInfo {
    const char* name;
    void* address;
};

bool readDecaytree(const std::string& fileName, TTree* tree) {
    std::string directoryName = "Tuple";
    std::string treeName = "DecayTree";

    auto file = TFile::Open(fileName.c_str(), "READ");
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return false;
    }

    TDirectory* dir = file->GetDirectory(directoryName.c_str());

    tree = dir->Get<TTree>("DecayTree");

    if (!tree) {
        std::cerr << "Error: Could not find TTree in file " << fileName << std::endl;
        return false;
    } 

    file->Close();
    return true;
}

void printTTreeBranchNames(TTree* tree) {
    TObjArray* branches = tree->GetListOfBranches();

    for (int i = 0; i < branches->GetEntries(); ++i) {
        TBranch* branch = dynamic_cast<TBranch*>(branches->At(i));
        if (branch) {
            std::cout << "Branch Name: " << branch->GetName() << std::endl;
        }
    }
}

void plotBranch(TTree* tree, const char* branchName) {
    TCanvas* canvas = new TCanvas("canvas", branchName, 800, 600);
    tree->Draw(Form("%s>>histogram", branchName));
    canvas->Draw();
}

void multiplyAndPlot(TTree* tree, const char* branch1, const char* branch2) {
    TCanvas* canvas = new TCanvas("canvas", "MM Plot", 800, 600);

    TH1F* histogram = new TH1F("histogram", "MM Plot", 100, 0, 200);

    // Calculate the product and fill the histogram
    tree->Draw(Form("(%s + %s)>>histogram", branch1, branch2));

    // Customize the histogram (optional)
    // histogram->GetXaxis()->SetTitle("X-axis label");
    // histogram->GetYaxis()->SetTitle("Y-axis label");
    // histogram->SetLineColor(kBlue);
    // histogram->SetLineWidth(2);

    histogram->Draw();
    canvas->Draw();
}

Double_t calculateMomentum(Double_t PX, Double_t PY, Double_t PZ) {
    return TMath::Sqrt(PX * PX + PY * PY + PZ * PZ);
}

Double_t calculatePseudorapidity(Double_t PX, Double_t PY, Double_t PZ) {
    return TMath::ATanH(PZ / calculateMomentum(PX, PY, PZ));
}

Double_t calculateAzimuthalAngle(Double_t PX, Double_t PY) {
    return TMath::ATan2(PY, PX);
}

TH1F* plotInvariantMassComplexCalculation(TTree* decayTree) {
    Double_t muon1_M, muon1_PX, muon1_PY, muon1_PZ, muon1_PT;
    Double_t muon2_M, muon2_PX, muon2_PY, muon2_PZ, muon2_PT;

    decayTree->SetBranchAddress("muon1_M", &muon1_M);
    decayTree->SetBranchAddress("muon1_PX", &muon1_PX);
    decayTree->SetBranchAddress("muon1_PY", &muon1_PY);
    decayTree->SetBranchAddress("muon1_PZ", &muon1_PZ);
    decayTree->SetBranchAddress("muon1_PT", &muon1_PT);
    decayTree->SetBranchAddress("muon2_M", &muon2_M);
    decayTree->SetBranchAddress("muon2_PX", &muon2_PX);
    decayTree->SetBranchAddress("muon2_PY", &muon2_PY);
    decayTree->SetBranchAddress("muon2_PZ", &muon2_PZ);
    decayTree->SetBranchAddress("muon2_PT", &muon2_PT);

    TH1F* histogram = new TH1F("invariant_mass_complex_calc", "Invariant mass plot", 100, 35000, 140000);

    int numEntries = decayTree->GetEntries();
    for (int i = 0; i < numEntries; ++i) {
        decayTree->GetEntry(i);

        float muon1_eta = calculatePseudorapidity(muon1_PX, muon1_PY, muon1_PZ);
        float muon1_phi = calculateAzimuthalAngle(muon1_PX, muon1_PY);

        float muon2_eta = calculatePseudorapidity(muon2_PX, muon2_PY, muon2_PZ);
        float muon2_phi = calculateAzimuthalAngle(muon2_PX, muon2_PY);

        TLorentzVector muon1, muon2;

        muon1.SetPtEtaPhiM(muon1_PT, muon1_eta, muon1_phi, muon1_M);
        muon2.SetPtEtaPhiM(muon2_PT, muon2_eta, muon2_phi, muon2_M);

        TLorentzVector total = muon1 + muon2;
        float invariantMass = total.M();

        histogram->Fill(invariantMass);
    }

    return histogram;
}

TH1F* plotInvariantMassSimpleCalculation(TTree* decayTree) {
    Double_t muon1_M, muon1_PX, muon1_PY, muon1_PZ;
    Double_t muon2_M, muon2_PX, muon2_PY, muon2_PZ;

    decayTree->SetBranchAddress("muon1_M", &muon1_M);
    decayTree->SetBranchAddress("muon1_PX", &muon1_PX);
    decayTree->SetBranchAddress("muon1_PY", &muon1_PY);
    decayTree->SetBranchAddress("muon1_PZ", &muon1_PZ);
    decayTree->SetBranchAddress("muon2_M", &muon2_M);
    decayTree->SetBranchAddress("muon2_PX", &muon2_PX);
    decayTree->SetBranchAddress("muon2_PY", &muon2_PY);
    decayTree->SetBranchAddress("muon2_PZ", &muon2_PZ);

    TH1F* invariantMassHistogram = new TH1F("invariant_mass_simple_calc", "Invariant Mass", 100, 35000, 140000);

    int nEntries = decayTree->GetEntries();
    for (int i = 0; i < nEntries; ++i) {
        decayTree->GetEntry(i);

        auto E1 = TMath::Sqrt(muon1_M*muon1_M + muon1_PX*muon1_PX + muon1_PY*muon1_PY + muon1_PZ*muon1_PZ);
        auto E2 = TMath::Sqrt(muon2_M*muon2_M + muon2_PX*muon2_PX + muon2_PY*muon2_PY + muon2_PZ*muon2_PZ);

        auto PX = muon1_PX + muon2_PX;
        auto PY = muon1_PY + muon2_PY;
        auto PZ = muon1_PZ + muon2_PZ;

        auto invariantMass = TMath::Sqrt((E1 + E2)*(E1 + E2) - PX*PX - PY*PY - PZ*PZ);

        invariantMassHistogram->Fill(invariantMass);
    }

    return invariantMassHistogram;
}

TH1F* plotInvariantMassTLorenzCalculation(TTree* decayTree) {
    Double_t muon1_M, muon1_PX, muon1_PY, muon1_PZ;
    Double_t muon2_M, muon2_PX, muon2_PY, muon2_PZ;

    decayTree->SetBranchAddress("muon1_M", &muon1_M);
    decayTree->SetBranchAddress("muon1_PX", &muon1_PX);
    decayTree->SetBranchAddress("muon1_PY", &muon1_PY);
    decayTree->SetBranchAddress("muon1_PZ", &muon1_PZ);
    decayTree->SetBranchAddress("muon2_M", &muon2_M);
    decayTree->SetBranchAddress("muon2_PX", &muon2_PX);
    decayTree->SetBranchAddress("muon2_PY", &muon2_PY);
    decayTree->SetBranchAddress("muon2_PZ", &muon2_PZ);

    TH1F* invariantMassHistogram = new TH1F("invariant_mass_tlorenz_calc", "Invariant Mass", 100, 35000, 140000);

    int nEntries = decayTree->GetEntries();
    for (int i = 0; i < nEntries; ++i) {
        decayTree->GetEntry(i);

        // Create TLorentzVectors for each muon
        TLorentzVector muon1(muon1_PX, muon1_PY, muon1_PZ, TMath::Sqrt(muon1_M*muon1_M + muon1_PX*muon1_PX + muon1_PY*muon1_PY + muon1_PZ*muon1_PZ));
        TLorentzVector muon2(muon2_PX, muon2_PY, muon2_PZ, TMath::Sqrt(muon2_M*muon2_M + muon2_PX*muon2_PX + muon2_PY*muon2_PY + muon2_PZ*muon2_PZ));

        // Calculate invariant mass
        TLorentzVector total = muon1 + muon2;
        float invariantMass = total.M();

        // Fill the histogram
        invariantMassHistogram->Fill(invariantMass);
    }

    return invariantMassHistogram;
}


void plotInvariantMassCalculationComparison(TTree* decayTree) {
    TCanvas* canvas = new TCanvas("canvas", "Invariant Mass Distribution", 800, 600);

    auto invariantMassHistogramTLorenz = plotInvariantMassTLorenzCalculation(decayTree);
    invariantMassHistogramTLorenz->SetLineColor(kGreen);

    auto invariantMassHistogramSimple = plotInvariantMassSimpleCalculation(decayTree);
    invariantMassHistogramSimple->SetLineColor(kBlue);

    auto invariantMassHistogramComplex = plotInvariantMassComplexCalculation(decayTree);
    invariantMassHistogramComplex->SetLineColor(kRed);




    THStack* stack = new THStack("PT_Stack", "Invariant mass distribution");
    stack->Add(invariantMassHistogramTLorenz);
    stack->Add(invariantMassHistogramSimple);
    stack->Add(invariantMassHistogramComplex);

    stack->Draw("nostack");

    // Add legend
    TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(invariantMassHistogramTLorenz, "TLorenz vector");
    legend->AddEntry(invariantMassHistogramSimple, "Simple energy calculation");
    legend->AddEntry(invariantMassHistogramComplex, "Angle calculations");
    legend->Draw();


    stack->GetXaxis()->SetTitle("Invariant Mass (MeV/c^2)");
    stack->GetYaxis()->SetTitle("Frequency");

    canvas->Draw();
}

void plotCutFlowHistogram(TTree* tree) {
    const int AMOUNT_OF_CRITERIA = 10;

    // Create a canvas to display the histogram
    TCanvas* canvas = new TCanvas("canvas", "Cut Flow Histogram", 800, 600);

    // Create a cut flow histogram with labeled bins
    TH1F* cutFlowHistogram = new TH1F("cutFlowHistogram", "Cut Flow", AMOUNT_OF_CRITERIA, 0.5, 20.5);

    // Define selection criteria labels
    const char* criteriaLabels[AMOUNT_OF_CRITERIA] = {
        "All",
        "is muon pair",
        "PT",
        "Z_MMERR",
        "Prob muon 90",
        "Prob muon 50",
        "Prob muon one 90",
        "Prob pion <10",
        "Prob electron <10",
        "Prob proton <10",
    };

    // Set labels for each bin
    for (int i = 1; i <= AMOUNT_OF_CRITERIA; ++i) {
        cutFlowHistogram->GetXaxis()->SetBinLabel(i, criteriaLabels[i - 1]);
    }

    // Load variables
    Bool_t muon1_isMuon, muon2_isMuon;
    Double_t muon1_PT, muon1_ProbNNmu, muon1_ProbNNpi, muon1_ProbNNe, muon1_ProbNNp,
             muon2_PT, muon2_ProbNNmu, muon2_ProbNNpi, muon2_ProbNNe, muon2_ProbNNp,
             Z_MMERR;

    BranchInfo branches[] = {
        {"muon1_isMuon", &muon1_isMuon},
        {"muon2_isMuon", &muon2_isMuon},
        {"muon1_PT", &muon1_PT},
        {"muon2_PT", &muon2_PT},
        {"Z_MMERR", &Z_MMERR},
        {"muon1_ProbNNmu", &muon1_ProbNNmu},
        {"muon2_ProbNNmu", &muon2_ProbNNmu},
        {"muon1_ProbNNp", &muon1_ProbNNp},
        {"muon2_ProbNNp", &muon2_ProbNNp},
        {"muon1_ProbNNpi", &muon1_ProbNNpi},
        {"muon2_ProbNNpi", &muon2_ProbNNpi},
        {"muon1_ProbNNe", &muon1_ProbNNe},
        {"muon2_ProbNNe", &muon2_ProbNNe},
    };

    for (auto& branch : branches) {
        tree->SetBranchAddress(branch.name, branch.address);
    }

    // Loop over your events and apply selection criteria
    int totalEvents = tree->GetEntries();
    int passedEvents = totalEvents;

    
    // Fill the cut flow histogram
    cutFlowHistogram->Fill("All", totalEvents);

    // === IS MUON PAIR ===
    for (int i = 0; i < totalEvents; ++i) {
        tree->GetEntry(i);
        if (!muon1_isMuon || !muon2_isMuon) {
            passedEvents -= 1;
        }
    }
    cutFlowHistogram->Fill("is muon pair", passedEvents);
    passedEvents = totalEvents;

    // === p_T cut ===
    for (int i = 0; i < totalEvents; ++i) {
        tree->GetEntry(i);
        if (muon1_PT < 25000 && muon2_PT < 25000) {
            passedEvents -= 1;
        }
    }
    cutFlowHistogram->Fill("PT", passedEvents);
    passedEvents = totalEvents;

    // === Z_MMERR ===
    for (int i = 0; i < totalEvents; ++i) {
        tree->GetEntry(i);
        if (Z_MMERR > 4500) { // Roughly 5%
            passedEvents -= 1;
        }
    }
    cutFlowHistogram->Fill("Z_MMERR", passedEvents);
    passedEvents = totalEvents;

    // === Bayesian posteriori probability: \mu  90 ===
    for (int i = 0; i < totalEvents; ++i) {
        tree->GetEntry(i);
        if (muon1_ProbNNmu < 0.9 || muon2_ProbNNmu < 0.9) {
            passedEvents -= 1;
        }
    }
    cutFlowHistogram->Fill("Prob muon 90", passedEvents);
    passedEvents = totalEvents;

    // === Bayesian posteriori probability: \mu  50 ===
    for (int i = 0; i < totalEvents; ++i) {
        tree->GetEntry(i);
        if (muon1_ProbNNmu < 0.5 || muon2_ProbNNmu < 0.5) {
            passedEvents -= 1;
        }
    }
    cutFlowHistogram->Fill("Prob muon 50", passedEvents);
    passedEvents = totalEvents;

    // === Bayesian posteriori probability: \mu one 90 ===
    for (int i = 0; i < totalEvents; ++i) {
        tree->GetEntry(i);
        if (muon1_ProbNNmu < 0.9 && muon2_ProbNNmu < 0.9) {
            passedEvents -= 1;
        }
    }
    cutFlowHistogram->Fill("Prob muon one 90", passedEvents);
    passedEvents = totalEvents;

    // === Bayesian posteriori probability: \pi  <10 ===
    for (int i = 0; i < totalEvents; ++i) {
        tree->GetEntry(i);
        if (muon1_ProbNNpi > 0.1 || muon2_ProbNNpi > 0.1) {
            passedEvents -= 1;
        }
    }
    cutFlowHistogram->Fill("Prob pion <10", passedEvents);
    passedEvents = totalEvents;

    // === Bayesian posteriori probability: \e  <10 ===
    for (int i = 0; i < totalEvents; ++i) {
        tree->GetEntry(i);
        if (muon1_ProbNNe > 0.1 || muon2_ProbNNe > 0.1) {
            passedEvents -= 1;
        }
    }
    cutFlowHistogram->Fill("Prob electron <10", passedEvents);
    passedEvents = totalEvents;


    // === Bayesian posteriori probability: \p  <10 ===
    for (int i = 0; i < totalEvents; ++i) {
        tree->GetEntry(i);
        if (muon1_ProbNNp > 0.1 || muon2_ProbNNp > 0.1) {
            passedEvents -= 1;
        }
    }
    cutFlowHistogram->Fill("Prob proton <10", passedEvents);
    passedEvents = totalEvents;



    cutFlowHistogram->GetYaxis()->SetTitle("Number of Events");
    cutFlowHistogram->SetTitle("Cut Flow Histogram");

    cutFlowHistogram->Draw("vbar");
    canvas->Draw();
}

void plotPTLeading(TTree* tree) {
    TCanvas* canvas = new TCanvas("canvas", "p_t leading", 800, 600);

    // auto maxValueXAxis = TMath::Max(tree->GetMaximum("muon1_PT"), tree->GetMaximum("muon2_PT"));
    TH1F* histogram = new TH1F("histogram", "p_t leading plot", 100, 8000, 130000);

    Double_t muon1_PT, muon2_PT;
    tree->SetBranchAddress("muon1_PT", &muon1_PT);
    tree->SetBranchAddress("muon2_PT", &muon2_PT);

    int numEntries = tree->GetEntries();
    for (int i = 0; i < numEntries; ++i) {
        tree->GetEntry(i);

        Double_t leading_PT = TMath::Max(muon1_PT, muon2_PT);

        histogram->Fill(leading_PT);
    }

    histogram->Draw();
    canvas->Draw();
}

void plotPTNotLeading(TTree* tree) {
    TCanvas* canvas = new TCanvas("canvas", "p_t not leading", 800, 600);

    TH1F* histogram = new TH1F("histogram", "p_t not leading plot", 100, 8000, 130000);

    Double_t muon1_PT, muon2_PT;
    tree->SetBranchAddress("muon1_PT", &muon1_PT);
    tree->SetBranchAddress("muon2_PT", &muon2_PT);

    int numEntries = tree->GetEntries();
    for (int i = 0; i < numEntries; ++i) {
        tree->GetEntry(i);

        Double_t subleading_PT = TMath::Min(muon1_PT, muon2_PT);

        histogram->Fill(subleading_PT);
    }

    histogram->Draw();
    canvas->Draw();
}

void plotMuonPT(TTree* tree) {
    TCanvas* canvas = new TCanvas("canvas", "p_t not leading", 800, 600);

    TH1F* histogramLeadingPT = new TH1F("histogram1", "Leading Muon PT", 100, 8000, 130000);
    histogramLeadingPT->SetLineColor(kGreen);

    TH1F* histogramSubleadingPT = new TH1F("histogram2", "Subleading Muon PT", 100, 8000, 130000);
    histogramSubleadingPT->SetLineColor(kRed);

    Double_t muon1_PT, muon2_PT;
    tree->SetBranchAddress("muon1_PT", &muon1_PT);
    tree->SetBranchAddress("muon2_PT", &muon2_PT);

    int numEntries = tree->GetEntries();
    for (int i = 0; i < numEntries; ++i) {
        tree->GetEntry(i);

        Double_t leading_PT = TMath::Max(muon1_PT, muon2_PT);
        Double_t subleading_PT = TMath::Min(muon1_PT, muon2_PT);

        histogramLeadingPT->Fill(leading_PT);
        histogramSubleadingPT->Fill(subleading_PT);
    }

    THStack* stack = new THStack("PT_Stack", "Muon PT Distribution");
    stack->Add(histogramLeadingPT);
    stack->Add(histogramSubleadingPT);

    stack->Draw("nostack");

    // Add legend
    TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(histogramLeadingPT, "Leading Muon PT");
    legend->AddEntry(histogramSubleadingPT, "Subleading Muon PT");
    legend->Draw();

    // Set axis labels
    stack->GetXaxis()->SetTitle("PT");
    stack->GetYaxis()->SetTitle("Frequency");

    canvas->Draw();
}

void plotProbNNmu(TTree* tree) {
    TCanvas* canvas = new TCanvas("canvas", "ProbNNmu plots", 800, 600);

    TH1F* histogramProbNNmuMuon1 = new TH1F("histogram1", "ProbNNmuMuon1", 100, 0, 1);
    histogramProbNNmuMuon1->SetLineColor(kGreen);

    TH1F* histogramProbNNmuMuon2 = new TH1F("histogram2", "ProbNNmuMuon2", 100, 0, 1);
    histogramProbNNmuMuon2->SetLineColor(kBlue);

    Double_t muon1_ProbNNmu, muon2_ProbNNmu;
    tree->SetBranchAddress("muon1_ProbNNmu", &muon1_ProbNNmu);
    tree->SetBranchAddress("muon2_ProbNNmu", &muon2_ProbNNmu);

    int numEntries = tree->GetEntries();
    for (int i = 0; i < numEntries; ++i) {
        tree->GetEntry(i);

        histogramProbNNmuMuon1->Fill(muon1_ProbNNmu);
        histogramProbNNmuMuon2->Fill(muon2_ProbNNmu);
    }

    THStack* stack = new THStack("ProbNNmu_stack", "Muon Bayesian Posteriori Probability Distribution");
    stack->Add(histogramProbNNmuMuon1);
    stack->Add(histogramProbNNmuMuon2);

    stack->Draw("nostack");

    // Add legend
    TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(histogramProbNNmuMuon1, "muon1");
    legend->AddEntry(histogramProbNNmuMuon2, "muon2");
    legend->Draw();

    // Set axis labels
    stack->GetXaxis()->SetTitle("ProbNNmu");
    stack->GetYaxis()->SetTitle("Frequency");

    canvas->Draw();
}

void plotRapidity(TTree* decayTree) {
    TCanvas* canvas = new TCanvas("canvas", "Rapidity plot", 800, 600);

    TH1F* histogramLeadingRapidity = new TH1F("rapidity_leading", "Rapidity Leading", 100, 1, 5.5);
    histogramLeadingRapidity->SetLineColor(kGreen);

    TH1F* histogramSubleadingRapidity = new TH1F("rapidity_subleading", "Rapidity Subleading", 100, 1, 5.5);
    histogramSubleadingRapidity->SetLineColor(kRed);

    Double_t muon1_M, muon1_PX, muon1_PY, muon1_PZ;
    Double_t muon2_M, muon2_PX, muon2_PY, muon2_PZ;

    decayTree->SetBranchAddress("muon1_M", &muon1_M);
    decayTree->SetBranchAddress("muon1_PX", &muon1_PX);
    decayTree->SetBranchAddress("muon1_PY", &muon1_PY);
    decayTree->SetBranchAddress("muon1_PZ", &muon1_PZ);
    decayTree->SetBranchAddress("muon2_M", &muon2_M);
    decayTree->SetBranchAddress("muon2_PX", &muon2_PX);
    decayTree->SetBranchAddress("muon2_PY", &muon2_PY);
    decayTree->SetBranchAddress("muon2_PZ", &muon2_PZ);


    int nEntries = decayTree->GetEntries();
    for (int i = 0; i < nEntries; ++i) {
        decayTree->GetEntry(i);

        // Create TLorentzVectors for each muon
        TLorentzVector muon1(muon1_PX, muon1_PY, muon1_PZ, TMath::Sqrt(muon1_M*muon1_M + muon1_PX*muon1_PX + muon1_PY*muon1_PY + muon1_PZ*muon1_PZ));
        TLorentzVector muon2(muon2_PX, muon2_PY, muon2_PZ, TMath::Sqrt(muon2_M*muon2_M + muon2_PX*muon2_PX + muon2_PY*muon2_PY + muon2_PZ*muon2_PZ));

        Double_t rapidityLeading = muon1.Rapidity(); 
        double_t rapiditySubleading = muon2.Rapidity();

        if(muon1.Pt() < muon2.Pt()) {
            rapidityLeading = muon2.Rapidity(); 
            rapiditySubleading = muon1.Rapidity();
        }

        // Fill the histogram
        histogramLeadingRapidity->Fill(rapidityLeading);
        histogramSubleadingRapidity->Fill(rapiditySubleading);
    }

    THStack* stack = new THStack("Rapidity_stack", "Muon Rapidity Distribution");
    stack->Add(histogramLeadingRapidity);
    stack->Add(histogramSubleadingRapidity);

    stack->Draw("nostack");

    // Add legend
    TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(histogramLeadingRapidity, "Leading Muon Rapidity");
    legend->AddEntry(histogramSubleadingRapidity, "Subleading Muon Rapidity");
    legend->Draw();

    // Set axis labels
    stack->GetXaxis()->SetTitle("Rapidity");
    stack->GetYaxis()->SetTitle("Frequency");

    canvas->Draw();
}

void plotPseudorapidity(TTree* decayTree) {
        TCanvas* canvas = new TCanvas("canvas", "Rapidity plot", 800, 600);

    TH1F* histogramLeadingPseudorapidity = new TH1F("pseudorapidity_leading", "Pseudorapidity Leading", 100, 1, 5.5);
    histogramLeadingPseudorapidity->SetLineColor(kGreen);

    TH1F* histogramSubleadingPseudorapidity = new TH1F("pseudorapidity_subleading", "Pseudorapidity Subleading", 100, 1, 5.5);
    histogramSubleadingPseudorapidity->SetLineColor(kRed);

    Double_t muon1_M, muon1_PX, muon1_PY, muon1_PZ;
    Double_t muon2_M, muon2_PX, muon2_PY, muon2_PZ;

    decayTree->SetBranchAddress("muon1_M", &muon1_M);
    decayTree->SetBranchAddress("muon1_PX", &muon1_PX);
    decayTree->SetBranchAddress("muon1_PY", &muon1_PY);
    decayTree->SetBranchAddress("muon1_PZ", &muon1_PZ);
    decayTree->SetBranchAddress("muon2_M", &muon2_M);
    decayTree->SetBranchAddress("muon2_PX", &muon2_PX);
    decayTree->SetBranchAddress("muon2_PY", &muon2_PY);
    decayTree->SetBranchAddress("muon2_PZ", &muon2_PZ);


    int nEntries = decayTree->GetEntries();
    for (int i = 0; i < nEntries; ++i) {
        decayTree->GetEntry(i);

        // Create TLorentzVectors for each muon
        TLorentzVector muon1(muon1_PX, muon1_PY, muon1_PZ, TMath::Sqrt(muon1_M*muon1_M + muon1_PX*muon1_PX + muon1_PY*muon1_PY + muon1_PZ*muon1_PZ));
        TLorentzVector muon2(muon2_PX, muon2_PY, muon2_PZ, TMath::Sqrt(muon2_M*muon2_M + muon2_PX*muon2_PX + muon2_PY*muon2_PY + muon2_PZ*muon2_PZ));

        Double_t pseudorapidityLeading = muon1.PseudoRapidity(); 
        double_t pseudorapiditySubleading = muon2.PseudoRapidity();

        if(muon1.Pt() < muon2.Pt()) {
            pseudorapidityLeading = muon2.PseudoRapidity(); 
            pseudorapiditySubleading = muon1.PseudoRapidity();
        }

        // Fill the histogram
        histogramLeadingPseudorapidity->Fill(pseudorapidityLeading);
        histogramSubleadingPseudorapidity->Fill(pseudorapiditySubleading);
    }

    THStack* stack = new THStack("Pseudorapidity_stack", "Muon Pseudo Rapidity Distribution");
    stack->Add(histogramLeadingPseudorapidity);
    stack->Add(histogramSubleadingPseudorapidity);

    stack->Draw("nostack");

    // Add legend
    TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(histogramLeadingPseudorapidity, "Leading Muon Pseudo Rapidity");
    legend->AddEntry(histogramSubleadingPseudorapidity, "Subleading Muon Pseudo Rapidity");
    legend->Draw();

    // Set axis labels
    stack->GetXaxis()->SetTitle("Pseudo Rapidity");
    stack->GetYaxis()->SetTitle("Frequency");

    canvas->Draw();
}

void plotLeptonSumPT(TTree* decayTree) {
    TCanvas* canvas = new TCanvas("canvas", "Lepton Sum PT", 800, 600);

    Double_t muon1_M, muon1_PX, muon1_PY, muon1_PZ;
    Double_t muon2_M, muon2_PX, muon2_PY, muon2_PZ;
    Double_t Z_PT;

    decayTree->SetBranchAddress("muon1_M", &muon1_M);
    decayTree->SetBranchAddress("muon1_PX", &muon1_PX);
    decayTree->SetBranchAddress("muon1_PY", &muon1_PY);
    decayTree->SetBranchAddress("muon1_PZ", &muon1_PZ);
    decayTree->SetBranchAddress("muon2_M", &muon2_M);
    decayTree->SetBranchAddress("muon2_PX", &muon2_PX);
    decayTree->SetBranchAddress("muon2_PY", &muon2_PY);
    decayTree->SetBranchAddress("muon2_PZ", &muon2_PZ);
    decayTree->SetBranchAddress("Z_PT", &Z_PT);

    TH1F* histogramSumPT = new TH1F("sum_PT", "Sum PT", 100, -1000, 120000);
    histogramSumPT->SetLineColor(kBlue);

    TH1F* histogramZPT = new TH1F("Z_PT", "Z PT", 100, -1000, 120000);
    histogramZPT->SetLineColor(kGreen);

    int nEntries = decayTree->GetEntries();
    for (int i = 0; i < nEntries; ++i) {
        decayTree->GetEntry(i);

        TLorentzVector muon1(muon1_PX, muon1_PY, muon1_PZ, TMath::Sqrt(muon1_M*muon1_M + muon1_PX*muon1_PX + muon1_PY*muon1_PY + muon1_PZ*muon1_PZ));
        TLorentzVector muon2(muon2_PX, muon2_PY, muon2_PZ, TMath::Sqrt(muon2_M*muon2_M + muon2_PX*muon2_PX + muon2_PY*muon2_PY + muon2_PZ*muon2_PZ));

        TLorentzVector total = muon1 + muon2;
        float PT = total.Pt();

        histogramSumPT->Fill(PT);
        histogramZPT->Fill(Z_PT);
    }

    THStack* stack = new THStack("Sum_PT_stack", "Lepton sum PT Distribution");
    stack->Add(histogramSumPT);
    stack->Add(histogramZPT);

    stack->Draw("nostack");

    // Add legend
    TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(histogramSumPT, "TLorentzVector Pt()");
    legend->AddEntry(histogramZPT, "Z_PT");
    legend->Draw();

    // Set axis labels
    stack->GetXaxis()->SetTitle("PT");
    stack->GetYaxis()->SetTitle("Frequency");

    canvas->Draw();
}

void plotLeptonSumRapidity(TTree* decayTree) {
    TCanvas* canvas = new TCanvas("canvas", "Lepton Sum Rapidity", 800, 600);

    Double_t muon1_M, muon1_PX, muon1_PY, muon1_PZ;
    Double_t muon2_M, muon2_PX, muon2_PY, muon2_PZ;

    decayTree->SetBranchAddress("muon1_M", &muon1_M);
    decayTree->SetBranchAddress("muon1_PX", &muon1_PX);
    decayTree->SetBranchAddress("muon1_PY", &muon1_PY);
    decayTree->SetBranchAddress("muon1_PZ", &muon1_PZ);
    decayTree->SetBranchAddress("muon2_M", &muon2_M);
    decayTree->SetBranchAddress("muon2_PX", &muon2_PX);
    decayTree->SetBranchAddress("muon2_PY", &muon2_PY);
    decayTree->SetBranchAddress("muon2_PZ", &muon2_PZ);

    TH1F* histogramSumRapidity = new TH1F("sum_Rapidity", "Sum Rapidity", 100, 1, 5.5);
    histogramSumRapidity->SetLineColor(kBlue);

    int nEntries = decayTree->GetEntries();
    for (int i = 0; i < nEntries; ++i) {
        decayTree->GetEntry(i);

        TLorentzVector muon1(muon1_PX, muon1_PY, muon1_PZ, TMath::Sqrt(muon1_M*muon1_M + muon1_PX*muon1_PX + muon1_PY*muon1_PY + muon1_PZ*muon1_PZ));
        TLorentzVector muon2(muon2_PX, muon2_PY, muon2_PZ, TMath::Sqrt(muon2_M*muon2_M + muon2_PX*muon2_PX + muon2_PY*muon2_PY + muon2_PZ*muon2_PZ));

        TLorentzVector total = muon1 + muon2;
        Double_t rapidity = total.Rapidity();

        histogramSumRapidity->Fill(rapidity);
    }

    histogramSumRapidity->Draw();

    // Set axis labels
    histogramSumRapidity->GetXaxis()->SetTitle("Rapidity");
    histogramSumRapidity->GetYaxis()->SetTitle("Frequency");

    canvas->Draw();
}

void analyse() {
    std::string fileName = "../data/2011Up.root";
    
    // ======================================================
    // READ TREE
    // ------------------------------------------------------
    std::string directoryName = "Tuple";
    std::string treeName = "DecayTree";

    auto file = TFile::Open(fileName.c_str(), "READ");
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }

    TDirectory* dir = file->GetDirectory(directoryName.c_str());

    auto decayTree = dir->Get<TTree>("DecayTree");

    if (!decayTree) {
        std::cerr << "Error: Could not find TTree in file " << fileName << std::endl;
        return;
    } 

    // printTTreeBranchNames(decayTree);
    // decayTree->Print();

    // ======================================================
    // DISPLAY STUFF
    // ------------------------------------------------------
    // plotBranch(decayTree, "Z_MM");
    // plotBranch(decayTree, "muon2_M");
    // multiplyAndPlot(decayTree, "muon1_M", "muon2_M");

    // plotInvariantMass(decayTree);

    // plotPTLeading(decayTree);
    // plotPTNotLeading(decayTree);
    // plotMuonPT(decayTree);

    // plotInvariantMassCalculationComparison(decayTree);

    // plotProbNNmu(decayTree);

    // plotRapidity(decayTree);

    plotPseudorapidity(decayTree);

    // plotLeptonSumPT(decayTree);

    // plotLeptonSumRapidity(decayTree);
    

    // ======================================================
    // DISPLAY CUT FLOW
    // ------------------------------------------------------
    // plotCutFlowHistogram(decayTree);
    

    // ======================================================
    // Persist run
    // ------------------------------------------------------
    // int i = 0;
    // std::cin >> i;
}