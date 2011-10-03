#ifndef FEATUREPLUGINMANAGER_H
#define FEATUREPLUGINMANAGER_H

#include "PluginLoader.h"
#include "PluginType.h"
#include "VisualFeatureAlgorithm.h"

namespace vito{
namespace features{

class FeaturePluginManager : public PluginType<VisualFeatureAlgorithm> {
private:
  PluginLoader loader;
  static factory& getFactory_();
public:
  const factory &getFactory() const;
  FeaturePluginManager(PluginLoader::filelist list) : loader(list){}
  ~FeaturePluginManager();
};

} // features
} // vito



#endif
