#include "ClassifierFactory.h"

typedef vito::classification::ClassifierFactory::factory factory;
factory classification_factory;

namespace vito{
namespace classification{

const factory& ClassifierFactory::getFactory() const{
  return classification_factory;
}

} // classification
} // vito
