#ifndef FEATUREFACTORY_H
#define FEATUREFACTORY_H

#include "FileSystem.h"
#include "FeaturePluginManager.h"
#include "XMLParameterDataSource.h"

namespace vito{
namespace features{

class FeatureFactory{
private:
  FileSystem::ptr filesystem;
  ParameterDataSource::ptr default_dsource;
  FeaturePluginManager manager;

public:
  FeatureFactory(FileSystem::ptr fs,
		 ParameterDataSource::ptr dsource) : 
    filesystem(fs),
    default_dsource(dsource), 
    manager(filesystem->getFilesOfType(".dylib", FEATUREPLUGINDIR)){
    //
  }

  VisualFeatureAlgorithm::ptr getFeatureAlgorithm(std::string featurename, 
					 ParameterDataSource::const_ptr source =
					 ParameterDataSource::const_ptr());
};

}
}

#endif
