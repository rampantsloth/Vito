#ifndef CLASSIFIERFACTORY_H
#define CLASSIFIERFACTORY_H

#include "PluginFactory.h"
#include "ClassifierAlgorithm.h"

namespace vito{
namespace classification{

class ClassifierFactory : public PluginFactory<ClassifierAlgorithm>{
protected:
  const factory &getFactory() const;
public:
  ClassifierFactory(FileSystem::ptr fs,
		    ParameterDataSource::ptr dsource,
		    std::string plugin_directory) : 
    PluginFactory<ClassifierAlgorithm>(fs, dsource, plugin_directory){}
};

} // classification
} // vito

#endif

