#ifndef GraphingManager_h
#define GraphingManager_h

#include <TH1.h>
#include <TCanvas.h>
#include <unordered_map>
#include <vector>

#include "HistogramConfig.h"


class GraphingManager {
public:
  GraphingManager(std::vector<CanvasConfig> canvasConfigurations);

  std::vector<CanvasConfig> canvasConfigurations;
  std::unordered_map<std::string, TH1F *> histogramDictionary;

  virtual void Fill(std::string histogramName, TH1F* histogramSource);
  virtual void Draw();
  virtual void Print();

private:
  virtual std::unordered_map<std::string, TCanvas *> SetUpCanvases();
  virtual void LoadConfig(std::vector<CanvasConfig> canvasConfigurations);
  virtual void CreateHistograms();
};

#endif
