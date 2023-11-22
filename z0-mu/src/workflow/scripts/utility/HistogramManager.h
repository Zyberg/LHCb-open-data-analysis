#ifndef HISTOGRAM_MANAGER_H
#define HISTOGRAM_MANAGER_H

#include <TH1.h>
#include <unordered_map>
#include <vector>
#include <string>

#include "HistogramConfig.h"


class HistogramManager {
public:
  HistogramManager(std::vector<HistogramConfig> histogramsConfig);

  std::vector<HistogramConfig> histogramsConfig;
  std::unordered_map<std::string, TH1F *> histogramDictionary;

  virtual void LoadConfig(std::vector<HistogramConfig> histogramsConfig);
  virtual void Save(std::string outputFileName);

private:
  virtual void CreateHistograms();
};

#endif
