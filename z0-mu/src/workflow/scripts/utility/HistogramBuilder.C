#include "HistogramBuilder.h"
#include <iostream>

HistogramBuilder::HistogramBuilder(const std::string& filename, const std::string& namecycle) {
    file = new TFile(filename.c_str(), "READ");
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    tree = (TTree*)file->Get(namecycle.c_str());

    if (!tree) {
        std::cerr << "Error: Could not find TTree in file " << filename << std::endl;
        return;
    }
}

HistogramBuilder::~HistogramBuilder() {
    file->Close();
    delete file;
}

void HistogramBuilder::FillExternalHistogram(const std::string& expression, TH1F* histogram) {
    std::cout << (expression + " >> " + histogram->GetName()).c_str() << std::endl;
    tree->Draw((expression + " >> " + histogram->GetName()).c_str());
}
