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
  typedef std::vector<Descriptor::const_ptr> DescriptorPtrSet;
  typedef boost::shared_ptr<IVisualFeatureFetcher> ptr;
  virtual Descriptor::const_ptr extract(const DataPoint &dp, 
					RgbImage *visrep = 0) = 0;
   DescriptorPtrSet             extract(const vector<DataPoint> &dps);
};

} // features
}// vito
#endif
