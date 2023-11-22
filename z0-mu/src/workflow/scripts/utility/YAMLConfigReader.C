#include <iostream>
#include <fstream>
#include "YAMLConfigReader.h"

YAMLConfigReader::YAMLConfigReader(const std::string& filename) : valid(true) {
    try {
        YAML::Node node = YAML::LoadFile(filename);
        parseYAML(node);
    } catch (const YAML::Exception& e) {
        valid = false;
        error = e.what();
    }
}

bool YAMLConfigReader::isValid() const {
    return valid;
}

std::string YAMLConfigReader::getError() const {
    return error;
}

CanvasConfig YAMLConfigReader::getConfig() const {
    return config;
}

void YAMLConfigReader::parseYAML(const YAML::Node& node) {
    config.name = node["name"].as<std::string>();
    config.title = node["title"].as<std::string>();
    config.outputFilename = node["outputFilename"].as<std::string>();
    config.outputChartFilename = node["outputChartFilename"].as<std::string>();

    // Read HistogramConfigs
    const YAML::Node& histogramsNode = node["histograms"];
    for (const YAML::Node& histNode : histogramsNode) {
        HistogramConfig histConfig;
        histConfig.name = histNode["name"].as<std::string>();
        histConfig.title = histNode["title"].as<std::string>();
        histConfig.expression = histNode["expression"].as<std::string>();
        histConfig.nbinsx = histNode["nbinsx"].as<int>();
        histConfig.xlow = histNode["xlow"].as<Double_t>();
        histConfig.xup = histNode["xup"].as<Double_t>();
        histConfig.color = static_cast<EColor>(histNode["color"].as<int>());
        config.histograms.push_back(histConfig);
    }

    // Read StackConfig
    const YAML::Node& stackNode = node["stack"];
    config.stack.name = stackNode["name"].as<std::string>();
    config.stack.title = stackNode["title"].as<std::string>();
    config.stack.xaxisTitle = stackNode["xaxisTitle"].as<std::string>();
    config.stack.yaxisTitle = stackNode["yaxisTitle"].as<std::string>();
}
