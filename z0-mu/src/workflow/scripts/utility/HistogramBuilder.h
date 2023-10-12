#ifndef HISTOGRAMBUILDER_H
#define HISTOGRAMBUILDER_H

#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <vector>
#include <string>

class HistogramBuilder {
public:
    HistogramBuilder(const std::string& filename, const std::string& namecycle);
    ~HistogramBuilder();

    void FillExternalHistogram(const std::string& expression, TH1F* histogram);

private:
    TFile* file;
    TTree* tree;
};

#endif // HISTOGRAMBUILDER_H
