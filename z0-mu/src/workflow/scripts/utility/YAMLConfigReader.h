#ifndef YAMLCONFIGREADER_H
#define YAMLCONFIGREADER_H

#include <yaml-cpp/yaml.h>
#include <string>
#include <vector>
#include <TColor.h>
#include "HistogramConfig.h"


class YAMLConfigReader {
public:
    YAMLConfigReader(const std::string& filename);

    bool isValid() const;
    std::string getError() const;

    CanvasConfig getConfig() const;

private:
    bool valid;
    std::string error;
    CanvasConfig config;

    void parseYAML(const YAML::Node& node);
};

#endif // YAMLCONFIGREADER_H
