#ifndef IVISUALFEATUREFETCHER_H
#define IVISUALFEATUREFETCHER_H

#include "boost/shared_ptr.hpp"
#include "Descriptor.h"
#include "DataPoint.h"
#include "VisualFeatureAlgorithm.h"

namespace vito{
namespace features{

class IVisualFeatureFetcher{
public:
  typedef std::vector<const Descriptor *> DescriptorPtrSet;
  typedef boost::shared_ptr<IVisualFeatureFetcher> ptr;
  virtual const Descriptor * extract(const DataPoint *dp, 
				     RgbImage *visrep = 0) = 0;
   DescriptorPtrSet          extract(const vector<const DataPoint*> &dps);
};

} // features
}// vito
#endif
