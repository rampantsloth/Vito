#include "FeatureFactory.h"

using std::cout;
using std::endl;

namespace vito{
namespace features{

typedef VisualFeatureAlgorithm::ptr f_ptr;

f_ptr FeatureFactory::getFeatureAlgorithm(string featurename,
					  ParameterDataSource::const_ptr dsource){
  // if no datasource is named, use the default one
  if(dsource == NULL)
    dsource = default_dsource;
  const FeaturePluginManager::factory &feat_factory = manager.getFactory();
  if(feat_factory.count(featurename)){
    return (*feat_factory.find(featurename)).second(dsource);
  }else
    cout << "could not find " << featurename << " in the plugins" << endl;
  return f_ptr();
}


} // features
} // vito
