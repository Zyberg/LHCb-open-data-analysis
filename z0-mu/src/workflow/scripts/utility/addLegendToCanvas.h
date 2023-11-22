#ifndef ADD_LEGEND_TO_CANVAS_H
#define ADD_LEGEND_TO_CANVAS_H

#include "HistogramConfig.h"
#include "HistogramFitConfig.h"
#include <TCanvas.h>
#include <THStack.h>
#include <TH1.h>
#include <TF1.h>
#include <TLegend.h>


// TODO: reuse this inside graphing manager
inline void addLegendToCanvas(TCanvas *canvas, CanvasConfig canvasConfig, std::vector<HistogramFitFuncConfig> fitsConfig) {
  TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);

  // Add histograms
  for (const auto &histogramConfig : canvasConfig.histograms) {
    auto histogram = (TH1F*)canvas->GetListOfPrimitives()->FindObject(histogramConfig.name.c_str());

    legend->AddEntry(histogram, histogramConfig.title.c_str());
  }

  // Add fits
  for (const auto &fitConfig : fitsConfig) {
    auto fitFunc = (TF1*)(canvas->GetListOfPrimitives()->FindObject(fitConfig.name.c_str()));

    legend->AddEntry(fitFunc, fitConfig.title.c_str());
  }

  legend->Draw("same");

  canvas->Update();
}

#endif