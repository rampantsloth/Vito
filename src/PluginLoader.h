#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include "FeaturePlugins/FeatureAlgorithmPlugin.h"

namespace vito{

template<class Type> class PluginInterface{
public:
  void loadPlugins(std::string location){
  }   
 
};

class PluginFetcher{
  PluginInterface<FeatureMaker> features;
};

} // vito
#endif
