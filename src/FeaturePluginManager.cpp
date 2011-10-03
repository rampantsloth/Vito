#include "FeaturePluginManager.h"

typedef vito::features::FeaturePluginManager::factory factory;

factory factory_;

namespace vito{
namespace features{
 const factory &FeaturePluginManager::getFactory_(){
  return factory_;
}
const factory &FeaturePluginManager::getFactory(){
  return FeaturePluginManager::getFactory();
}

} // features
} // vito
