#include "GraphingManager.h"
#include <TH1.h>
#include <iostream>
#include <TLegend.h>
#include <THStack.h>
#include <TFile.h>

GraphingManager::GraphingManager(std::vector<CanvasConfig> canvasConfigurations) {
    this->LoadConfig(canvasConfigurations);
}

void GraphingManager::LoadConfig(std::vector<CanvasConfig> canvasConfigurations) {
  this->canvasConfigurations = canvasConfigurations;

  this->CreateHistograms();
}

void GraphingManager::CreateHistograms() {
  std::cout << "Creating histograms..." << std::endl;

  for (const auto &canvas : canvasConfigurations) {
    for (const auto &histogram : canvas.histograms) {
      TH1F *hist = new TH1F(histogram.name.c_str(), histogram.title.c_str(),
                            histogram.nbinsx, histogram.xlow, histogram.xup);
      hist->SetLineColor(histogram.color);
      histogramDictionary[histogram.name] = hist;

      std::cout << "Histogram has been created: \"" << histogram.name << "\";"
                << std::endl;
    }
  }

  std::cout << "Created all required histograms successfully!" << std::endl;
}

void GraphingManager::SetUpCanvases() {
  for (const auto &canvas : canvasConfigurations) {
    this->canvases[canvas.name] =
        new TCanvas(canvas.name.c_str(), canvas.title.c_str(), 800, 600);

    THStack *stack =
        new THStack(canvas.stack.name.c_str(), canvas.stack.title.c_str());
    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);

    for (const auto &histogram : canvas.histograms) {
      stack->Add(histogramDictionary[histogram.name]);

      legend->AddEntry(histogramDictionary[histogram.name],
                       histogram.title.c_str());
    }

    stack->Draw("nostack");
    legend->Draw();

    // Set axis labels
    stack->GetXaxis()->SetTitle(canvas.stack.xaxisTitle.c_str());
    stack->GetYaxis()->SetTitle(canvas.stack.yaxisTitle.c_str());
  }
}

void GraphingManager::Fill(std::string histogramName, TH1F* histogramSource) {
  this->histogramDictionary[histogramName] = (TH1F*) histogramSource->Clone();
}

void GraphingManager::Draw() {
  for (auto &pair : this->canvases) {
    TCanvas *canvas = pair.second;

    std::cout << pair.first << std::endl;

    canvas->Draw();
  }
}

void GraphingManager::Print() {
  for (const auto &canvas : canvasConfigurations) {
    std::cout << canvas.name << std::endl;

    this->canvases[canvas.name]->Print(canvas.outputChartFilename.c_str());
  }
}

void GraphingManager::Print(const std::string outputFilename) {
  for (const auto &canvas : canvasConfigurations) {
    std::cout << canvas.name << std::endl;

    this->canvases[canvas.name]->Print(outputFilename.c_str());

    this->canvases[canvas.name]->ls();
  }
}