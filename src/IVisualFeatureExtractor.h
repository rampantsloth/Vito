#ifndef IVISUALFEATUREEXTRACTOR_H
#define IVISUALFEATUREEXTRACTOR_H

#include "Descriptor.h"
#include "dataPoint.h"
#include "Image.h"
#include "boost/shared_ptr.hpp"

namespace vito{
namespace features{

class IVisualFeatureExtractor{
public:
  typedef boost::shared_ptr<IVisualFeatureExtractor> ptr;
  virtual std::string getName() = 0;
  virtual Descriptor extract(const DataPoint *dp, RgbImage * visrep = 0) = 0;
  virtual ~IVisualFeatureExtractor(){}
  virtual std::string getSpecification() const = 0;
};

}} // namespaces

#endif
