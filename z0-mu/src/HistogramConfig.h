#ifndef HISTOGRAM_CONFIG_H
#define HISTOGRAM_CONFIG_H

struct HistogramConfig {
    std::string name;
    std::string title;
    int nbinsx;
    Double_t xlow;
    Double_t xup;
    EColor color;
};

struct StackConfig {
    std::string name;
    std::string title;
    std::string xaxisTitle;
    std::string yaxisTitle;
};

struct CanvasConfig {
    std::string name;
    std::string title;
    std::vector<HistogramConfig> histograms;
    StackConfig stack;
};

#endif