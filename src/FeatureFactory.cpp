#include "FeatureFactory.h"

using std::cout;
using std::endl;

namespace vito{
namespace features{

typedef VisualFeatureAlgorithm::ptr f_ptr;

f_ptr FeatureFactory::getFeatureAlgorithm(string featurename,
					  ParameterDataSource::const_ptr dsource){
  // if no datasource is named, use the default one
  if(dsource != NULL)
    dsource = default_dsource;
  const FeaturePluginManager::factory &factory = manager.getFactory();
  if(factory.count(featurename)){
    return (*factory.find(featurename)).second(dsource);
  }else
    cout << "could not find " << featurename << " in the plugins" << endl;
  return f_ptr();
}


} // features
} // vito
