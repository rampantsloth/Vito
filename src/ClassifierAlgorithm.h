#ifndef CLASSIFIERALGORITHM_H
#define CLASSIFIERALGORITHM_H

#include "boost/shared_ptr.hpp"
#include <string>
#include "Descriptor.h"

namespace vito{
namespace classification{

class ClassifierAlgorithm{
public:
  typedef boost::shared_ptr<ClassifierAlgorithm> ptr;
  virtual ~ClassifierAlgorithm(){};
  virtual void train(ExampleCollection a) = 0;
  virtual Label classify(const Descriptor &descriptor) const = 0;
  virtual std::string getName() = 0;
};

}
}

#endif
