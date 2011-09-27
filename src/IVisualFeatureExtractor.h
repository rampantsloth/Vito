#ifndef IVISUALFEATUREEXTRACTOR_H
#define IVISUALFEATUREEXTRACTOR_H

#include "Descriptor.h"
#include "dataPoint.h"
#include "Image.h"

namespace vito{
namespace features{

class IVisualFeatureExtractor{
public:
  virtual std::string getName() = 0;
  virtual Descriptor extract(DataPoint dp, RgbImage * visrep = 0) = 0;
};

}} // namespaces

#endif
