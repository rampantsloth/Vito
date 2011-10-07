#ifndef FEATUREFACTORY_H
#define FEATUREFACTORY_H

#include "VisualFeatureExtractor.h"
#include "IVisualFeatureFetcher.h"
#include "PluginFactory.h"
#include "VisualFeatureAlgorithm.h"

namespace vito{
namespace features{

class FeatureFactory : public PluginFactory<VisualFeatureAlgorithm>{
  typedef IVisualFeatureFetcher Fetcher;
  typedef IVisualFeatureExtractor Extractor;
protected:
  const factory &getFactory() const;
public:
  FeatureFactory(FileSystem::ptr fs, 
		 ParameterDataSource::ptr dsource,
		 std::string plugin_directory) : 
    PluginFactory<VisualFeatureAlgorithm>(fs, dsource,  plugin_directory){
  }

  Extractor::ptr getExtractor(std::string str, 
			      bool stored = false,
			      bool normalized = true) ;
  Fetcher::ptr   getFetcher(std::string str,
			    bool stored = false,
			    bool normalized = true) ;

};

}
}

#endif
