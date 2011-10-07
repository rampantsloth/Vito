#ifndef STOREDFEATUREEXTRACTOR_H
#define STOREDFEATUREEXTRACTOR_H

#include "VisualFeatureDecorator.h"

namespace vito{
namespace features{

class StoredFeatureExtractor : public VisualFeatureDecorator{
public:
  StoredFeatureExtractor(IVisualFeatureExtractor::ptr e) :
    VisualFeatureDecorator(e){
  }
  virtual Descriptor extract(DataPoint dp, RgbImage *visrep = 0);
};

} // features
} // vito

#endif
