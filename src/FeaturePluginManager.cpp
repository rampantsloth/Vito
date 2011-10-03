#include "FeaturePluginManager.h"

typedef vito::features::FeaturePluginManager::factory factory;

factory factory_;

namespace vito{
namespace features{
 factory &FeaturePluginManager::getFactory_(){
  return factory_;
}
const factory &FeaturePluginManager::getFactory() const{
  return FeaturePluginManager::getFactory();
}
FeaturePluginManager::~FeaturePluginManager(){
  FeaturePluginManager::getFactory_().clear();
}


} // features
} // vito
