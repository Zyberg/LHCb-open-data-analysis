#include "utility/HistogramManager.C"
#include "utility/HistogramBuilder.C"
#include "utility/util.h"
#include <string>

inline const char NAMECYCLE[] = "DecayTreeAfterProcessing";

void generateHistogram(const std::string inputFileName, const std::string configFileName) {
  auto config = readHistogramConfig(configFileName);
  
  // Initialize histograms
  auto histogramManager = new HistogramManager(config.histograms);
  
  // Fill with data
  HistogramBuilder builder(inputFileName, NAMECYCLE);

  for (const auto &histogram : config.histograms) {
    builder.FillExternalHistogram(histogram.expression, histogramManager->histogramDictionary[histogram.name]);
  }

  // Save to file
  histogramManager->Save(config.outputFilename);
}