#define GraphingManager_cxx

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <string>
#include <iostream>

#include "utility/GraphingManager.h"
#include "utility/HistogramBuilder.C"
#include "utility/YAMLConfigReader.C"

inline const char NAMECYCLE[] = "DecayTreeAfterCutflow";

// TODO: pass only the config file name and store inputFileName inside the yaml
void draw(const std::string inputFileName, const std::string configFileName) {
  // Read config
  YAMLConfigReader reader(configFileName);

  if (!reader.isValid()) {
    std::cerr << "Error: " << reader.getError() << std::endl;
    return;
  }

  auto config = reader.getConfig();
  
  // Initialize histograms
  auto graphingManager = new GraphingManager();

  graphingManager->LoadConfig({ config });
  graphingManager->CreateHistograms();
  
  // Fill with data
  HistogramBuilder builder(inputFileName, NAMECYCLE);

  for (const auto &histogram : config.histograms) {
    builder.FillExternalHistogram(histogram.expression, graphingManager->histogramDictionary[histogram.name]);
  }

  // Save to file
  graphingManager->Print();
}