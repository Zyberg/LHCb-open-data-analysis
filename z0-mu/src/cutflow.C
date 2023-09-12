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

void cutflow() {
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
    

    // ======================================================
    // DISPLAY CUT FLOW
    // ------------------------------------------------------
     plotCutFlowHistogram(decayTree);
    

    // ======================================================
    // Persist run
    // ------------------------------------------------------
    // int i = 0;
    // std::cin >> i;
}