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
  typedef boost::shared_ptr<FeatureFactory> ptr;
  FeatureFactory(FileSystem::ptr fs, 
		 std::string plugin_directory) : 
    PluginFactory<VisualFeatureAlgorithm>(fs,  plugin_directory){
    std::string desc_ding;
    desc_ding = desc_ding + "./" + DESCRIPTORLOCATION;
    fs->createDir(desc_ding);
  }

  Extractor::ptr getExtractor(std::string str,
			      ParameterDataSource::ptr dsrc ,
			      bool stored,
			      bool normalized);
  Extractor::ptr getExtractor(std::string str,
			      ParameterDataSource::ptr dsrc);
  Fetcher::ptr getFetcher(string tr, ParameterDataSource::ptr ds,
			  bool stored, bool norm);
  Fetcher::ptr getFetcher(string tr, ParameterDataSource::ptr ds);

};

}
}

#endif
