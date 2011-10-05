#ifndef CLASSIFIERFACTORY_H
#define CLASSIFIERFACTORY_H

#include "PluginFactory.h"
#include "ClassifierAlgorithm.h"

namespace vito{
namespace classification{

class ClassifierFactory : public PluginFactory<ClassifierAlgorithm>{
protected:
  const factory &getFactory() const;
};

} // classification
} // vito

#endif

