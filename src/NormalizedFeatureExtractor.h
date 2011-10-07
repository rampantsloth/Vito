#ifndef NORMALIZEDFEATUREEXTRACTOR_H
#define NORMALIZEDFEATUREEXTRACTOR_H

#include "VisualFeatureDecorator.h"

namespace vito{
namespace features{

class NormalizedFeatureExtractor : public VisualFeatureDecorator{
public:
  NormalizedFeatureExtractor(IVisualFeatureExtractor::ptr e) : 
    VisualFeatureDecorator(e){
  }
  virtual Descriptor extract(DataPoint dp, RgbImage *visrep = 0);
  virtual std::string getName(){
    return "normalized_" + extractor->getName();
  }
};

} // features
} // vito

#endif
