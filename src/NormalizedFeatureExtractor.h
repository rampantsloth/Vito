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
  virtual Descriptor extract(const DataPoint *dp, RgbImage *visrep = 0);
  virtual std::string getName(){
    return "normalized_" + extractor->getName();
  }
  virtual std::string getSpecification() const{ 
    return extractor->getSpecification() + "normalized";
  }
};

} // features
} // vito

#endif
