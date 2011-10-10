#ifndef VISUAL_FEATURE_EXTRACTOR_H
#define VISUAL_FEATURE_EXTRACTOR_H

#include "IVisualFeatureExtractor.h"
#include "VisualFeatureAlgorithm.h"
#include "sharedPointer.h"
#include "boost/shared_ptr.hpp"
namespace vito{
namespace features{

/* resources that should be available to a feature fetcher */
class VisualFeatureExtractor : public IVisualFeatureExtractor {
private:
  VisualFeatureAlgorithm::ptr algorithm;
public:
  VisualFeatureExtractor(VisualFeatureAlgorithm::ptr alg) : 
    algorithm(alg){}
  // features name;
  virtual std::string getName(){return algorithm->getName();}
  virtual Descriptor  extract(const DataPoint *dp, RgbImage *visrep = 0){
    return algorithm->extract(ImageAccess(dp), visrep);
  }
  virtual std::string getSpecification() const{ 
    return algorithm->getSpecification();
  }
};

} // features
} // vito
#endif


