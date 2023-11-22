#include <Rtypes.h>
#include <TFile.h>
#include <TF1.h>
#include <TH1.h>
#include <THStack.h>
#include <TList.h>
#include <string>

#include "utility/GraphingManager.C"
#include "utility/HistogramConfig.h"
#include "utility/HistogramFitConfig.h"
#include "utility/util.h"
#include "utility/addFitToCanvas.h"
#include "utility/addLegendToCanvas.h"


void fit(const std::string inputFileName, const std::string configFileNameHistogram, const std::string configFileNameFit) {
  auto config = readHistogramConfig(configFileNameHistogram);
  
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

  graphingManager->SetUpCanvases();

  std::vector<HistogramFitFuncConfig> fitsConfig = {
    {
        "breitWigner",
        "Breit Wigner",
        kGreen
    },
    {
        "gaus",
        "Gaus",
        kRed
    }
  };

  for (const auto &histogramConfig : config.histograms) {
    std::cout << histogramConfig.name << std::endl;
    auto histogram = (TH1F*)file->Get(histogramConfig.name.c_str());

    for (const auto &fitConfig : fitsConfig) {
        TF1* fitFunc;

        // TODO: extract this mapping for reusability
        if (fitConfig.name == "breitWigner") {
            fitFunc = new TF1(fitConfig.name.c_str(), "breitwigner", histogramConfig.xlow, histogramConfig.xup);

            fitFunc->SetParameter(0, histogram->GetMaximum());
            fitFunc->SetParameter(1, histogram->GetMean());
            fitFunc->SetParameter(2, histogram->GetRMS());
        } else if (fitConfig.name == "gaus") {
            fitFunc = new TF1(fitConfig.name.c_str(), "gaus", histogramConfig.xlow, histogramConfig.xup);
        }

        addFitToCanvas(
            graphingManager->canvases["canvas_invariant_mass"],
            fitFunc,
            config.stack.name,
            histogramConfig.name,
            histogramConfig.title,
            fitConfig.color
        );
    }

    addLegendToCanvas(graphingManager->canvases["canvas_invariant_mass"], config, fitsConfig);
  }

  // Save images of canvases
  graphingManager->Print("../../results/fit/Z_MM.png");
}