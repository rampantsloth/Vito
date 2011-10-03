#ifndef FEATUREPLUGINMANAGER_H
#define FEATUREPLUGINMANAGER_H

#include "PluginLoader.h"
#include "PluginType.h"
#include "VisualFeatureAlgorithm.h"

namespace vito{
namespace features{

class FeaturePluginManager : public PluginType<VisualFeatureAlgorithm>,
			     public PluginLoader{
private:
  static const factory & getFactory_();
public:
  const factory& getFactory();
  FeaturePluginManager(PluginLoader::filelist list) : PluginLoader(list){}
};

} // features
} // vito



#endif
