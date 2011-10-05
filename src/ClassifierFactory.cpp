#include "ClassifierFactory.h"

typedef vito::classification::ClassifierFactory::factory factory;
factory classifier_factory;

namespace vito{
namespace classification{

const factory& ClassifierFactory::getFactory() const{
  return classifier_factory;
}

} // classification
} // vito
