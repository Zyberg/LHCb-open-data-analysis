#include "HistogramManager.h"
#include <iostream>
#include <vector>
#include <TFile.h>

HistogramManager::HistogramManager(std::vector<HistogramConfig> histogramsConfig) {
    this->LoadConfig(histogramsConfig);
}

void HistogramManager::LoadConfig(std::vector<HistogramConfig> histogramsConfig) {
  this->histogramsConfig = histogramsConfig;

  this->CreateHistograms();
}

void HistogramManager::CreateHistograms() {
  std::cout << "Creating histograms..." << std::endl;

  for (const auto &histogram : histogramsConfig) {
    TH1F *hist = new TH1F(histogram.name.c_str(), histogram.title.c_str(),
                        histogram.nbinsx, histogram.xlow, histogram.xup);
    hist->SetLineColor(histogram.color);
    histogramDictionary[histogram.name] = hist;

    std::cout << "Histogram has been created: \"" << histogram.name << "\";"
            << std::endl;
  }

  std::cout << "Created all required histograms successfully!" << std::endl;
}

void HistogramManager::Save(std::string outputFileName) {
  auto fileOutput = new TFile(outputFileName.c_str(), "RECREATE");
  
  for (const auto &histogram : histogramsConfig) {
    std::cout << "Saving \"" << histogram.name << "\" into file \"" << outputFileName << "\"" << std::endl;

    std::cout << histogram.name << "\t" << std::endl;
    this->histogramDictionary[histogram.name]->Write();

    // fileOutput->Close();
  }

  fileOutput->Close();
}
