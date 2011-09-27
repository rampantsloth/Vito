#ifndef VISUAL_FEATURE_EXTRACTOR_H
#define VISUAL_FEATURE_EXTRACTOR_H

#include "IVisualFeatureExtractor.h"
#include "VisualFeatureAlgorithm.h"
#include "sharedPointer.h"

namespace vito{
namespace features{

/* resources that should be available to a feature fetcher */
class VisualFeatureExtractor : public IVisualFeatureExtractor {
private:
  SP<VisualFeatureAlgorithm> algorithm;
public:
  VisualFeatureExtractor(SP<VisualFeatureAlgorithm> alg) : algorithm(alg){}
  // features name;
  virtual std::string getName(){return algorithm->getName();}
  virtual Descriptor  extract(DataPoint dp, RgbImage *visrep = 0){
    return algorithm->extract(ImageAccess(dp), visrep);
  }
};

} // features
} // vito
#endif


