#ifndef VISUAL_FEATURE_ALGORITHM_H
#define VISUAL_FEATURE_ALGORITHM_H

#include "imageAccess.h"
#include "descriptor.h"
#include "boost/shared_ptr.hpp"

namespace vito{
namespace features{

/* interface for a visual feature algorithm */
class VisualFeatureAlgorithm{
public:
  typedef boost::shared_ptr<VisualFeatureAlgorithm> ptr;
  virtual std::string       getName() = 0;
  virtual Descriptor        extract(ImageAccess image, 
				    RgbImage *visrep = 0) = 0;
  virtual ~VisualFeatureAlgorithm(){}
};



}// features
}// vito
#endif
