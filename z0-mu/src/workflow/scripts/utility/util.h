#ifndef UTIL_H
#define UTIL_H

#include "YAMLConfigReader.C"

inline CanvasConfig readHistogramConfig(const std::string configFileName) {
  YAMLConfigReader reader(configFileName);

  if (!reader.isValid()) {
    std::cerr << "Error: " << reader.getError() << std::endl;
    throw std::invalid_argument("Histogram config file \"" + configFileName + "\" was not valid!");
  }

  return reader.getConfig();
}

#endif