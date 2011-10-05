#include "FeatureFactory.h"

using std::cout;
using std::endl;

typedef vito::features::FeatureFactory::factory factory;
factory feature_factory;

namespace vito{
namespace features{

const factory& FeatureFactory::getFactory() const{
  return feature_factory;
}

} // features
} // vito
