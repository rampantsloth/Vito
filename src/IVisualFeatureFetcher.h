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
  typedef std::vector<const DataPoint*> dp_refs;
  typedef std::vector<Descriptor::const_ptr> DescriptorPtrSet;
  typedef boost::shared_ptr<IVisualFeatureFetcher> ptr;
  virtual Descriptor::const_ptr extract(const DataPoint *dp, 
					RgbImage *visrep = 0) = 0;
  DescriptorPtrSet           extract(const dp_refs &dps);

  Example              extractExample(const DataPoint *dp, RgbImage *visrep = 0);
  std::vector<Example> extractExamples(const dp_refs &dps);
  virtual std::string getSpecification() = 0;
};

} // features
}// vito
#endif
