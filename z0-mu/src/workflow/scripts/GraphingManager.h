#ifndef GraphingManager_h
#define GraphingManager_h

#include "HistogramConfig.h"
#include <TH1.h>
#include <TLegend.h>

class GraphingManager {
public :
    std::vector<CanvasConfig> canvasConfigurations;
    std::unordered_map<std::string, TH1F*> histogramDictionary;

    virtual void LoadConfig(std::vector<CanvasConfig> canvasConfigurations);
    virtual void CreateHistograms();
    virtual void FillHistogram(std::string key, Double_t value);
    virtual void Draw();
    virtual void Print();

private :
    virtual std::unordered_map<std::string, TCanvas*> SetUpCanvases();
};

#endif


#ifdef GraphingManager_cxx
void GraphingManager::LoadConfig(std::vector<CanvasConfig> canvasConfigurations)
{
    this->canvasConfigurations = canvasConfigurations;
}

void GraphingManager::CreateHistograms()
{
    std::cout << "Creating histograms..." << std::endl;

    for (const auto& canvas : canvasConfigurations) {
        for (const auto& histogram : canvas.histograms) {
            TH1F* hist = new TH1F(histogram.name.c_str(), histogram.title.c_str(), histogram.nbinsx, histogram.xlow, histogram.xup);
            hist->SetLineColor(histogram.color);
            histogramDictionary[histogram.name] = hist;

            std::cout << "Histogram has been created: \"" << histogram.name << "\";" << std::endl;
        }
    }

    std::cout << "Created all required histograms successfully!" << std::endl;
}

void GraphingManager::FillHistogram(std::string key, Double_t value)
{
    this->histogramDictionary[key]->Fill(value);
}

std::unordered_map<std::string, TCanvas*> GraphingManager::SetUpCanvases()
{
    std::unordered_map<std::string, TCanvas*> canvases;
    for (const auto& canvas : canvasConfigurations) {
        canvases[canvas.name] = new TCanvas(canvas.name.c_str(), canvas.title.c_str(), 800, 600);

        THStack* stack = new THStack(canvas.stack.name.c_str(), canvas.stack.title.c_str());
        TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);

        for (const auto& histogram : canvas.histograms) {
            stack->Add(histogramDictionary[histogram.name]);

            legend->AddEntry(histogramDictionary[histogram.name], histogram.title.c_str());
        }

        stack->Draw("nostack");
        legend->Draw();

        // Set axis labels
        stack->GetXaxis()->SetTitle(canvas.stack.xaxisTitle.c_str());
        stack->GetYaxis()->SetTitle(canvas.stack.yaxisTitle.c_str());
    }

    return canvases;
}

void GraphingManager::Draw()
{
    auto canvases = this->SetUpCanvases();

    for (auto& pair : canvases) {
        TCanvas* canvas = pair.second;

        std::cout << pair.first << std::endl;

        canvas->Draw();
    }
}

void GraphingManager::Print()
{
    auto canvases = this->SetUpCanvases();

    for (const auto& canvas : canvasConfigurations) {
        std::cout << canvas.name << std::endl;

        canvases[canvas.name]->Print(canvas.outputFilename.c_str());
    }
}
#endif // #ifdef ZDecayAnalyser_cxx
