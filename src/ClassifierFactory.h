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
  typedef boost::shared_ptr<ClassifierFactory> ptr;
  ClassifierFactory(FileSystem::ptr fs,
		    std::string plugin_directory) : 
    PluginFactory<ClassifierAlgorithm>(fs, plugin_directory){}
};

} // classification
} // vito

#endif

