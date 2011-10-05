#ifndef FEATUREFACTORY_H
#define FEATUREFACTORY_H

#include "PluginFactory.h"
#include "VisualFeatureAlgorithm.h"

namespace vito{
namespace features{


class FeatureFactory : public PluginFactory<VisualFeatureAlgorithm>{
protected:
  const factory &getFactory() const;
public:
  FeatureFactory(FileSystem::ptr fs,
		 ParameterDataSource::ptr dsource,
		 std::string plugin_directory) : 
    PluginFactory<VisualFeatureAlgorithm>(fs, dsource,  plugin_directory){}
};

}
}

#endif
