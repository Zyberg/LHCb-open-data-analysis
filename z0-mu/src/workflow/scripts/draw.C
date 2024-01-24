#include <TFile.h>
#include <TH1.h>
#include <THStack.h>
#include <TList.h>
#include <string>

#include "utility/GraphingManager.C"
#include "utility/HistogramConfig.h"
#include "utility/util.h"

void draw(const std::string inputFileName, const std::string configFileName) {
  auto config = readHistogramConfig(configFileName);
  
  auto graphingManager = new GraphingManager({ config });

  auto file = new TFile(config.outputFilename.c_str(), "READ");

  if (!file || file->IsZombie()) {
    std::cerr << "Error: Could not open file " << config.outputFilename << std::endl;
  }

  for (const auto &histogram : config.histograms) {
    std::cout << histogram.name << std::endl;
    auto h = (TH1F*)file->Get(histogram.name.c_str());

    graphingManager->Fill(histogram.name, h);
  }

  // Save images of canvases
  graphingManager->SetUpCanvases();
  graphingManager->Print();
}

// mm 89427.789
// rms 8731.2264