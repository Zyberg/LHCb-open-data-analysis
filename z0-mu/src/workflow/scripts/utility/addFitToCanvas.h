#ifndef ADD_FIT_TO_CANVAS_H
#define ADD_FIT_TO_CANVAS_H

#include <TCanvas.h>
#include <THStack.h>
#include <TH1.h>
#include <TF1.h>
#include <TLegend.h>

inline void addFitToCanvas(TCanvas *canvas, TF1 *fitFunc, std::string stackName, std::string histogramName, std::string histogramLabel, Color_t color) {
    // Assuming histogram and stack already exist
    auto stack = (THStack*) canvas->FindObject(stackName.c_str());
    auto histogram = (TH1F *)stack->GetHists()->FindObject(histogramName.c_str());

    histogram->Fit(fitFunc->GetName(), "R+"); 

    stack->Draw("nostack");

    fitFunc->SetLineColor(color);
    fitFunc->Draw("same");

    // Update the canvas
    canvas->Update();
}

#endif