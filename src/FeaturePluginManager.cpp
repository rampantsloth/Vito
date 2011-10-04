#include "FeaturePluginManager.h"

typedef vito::features::FeaturePluginManager::factory factory;

factory feature_factory;

namespace vito{
namespace features{
 factory &FeaturePluginManager::getFactory_(){
  return feature_factory;
}
const factory &FeaturePluginManager::getFactory() const{
  return FeaturePluginManager::getFactory_();
}
FeaturePluginManager::~FeaturePluginManager(){
  FeaturePluginManager::getFactory_().clear();
}


} // features
} // vito
