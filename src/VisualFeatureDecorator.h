#ifndef VISUALFEATUREDECORATOR_H
#define VISUALFEATUREDECORATOR_H

#include "IVisualFeatureExtractor.h"

namespace vito{
namespace features{

class VisualFeatureDecorator : public IVisualFeatureExtractor{
protected:
  IVisualFeatureExtractor::ptr extractor;
public:
  VisualFeatureDecorator(IVisualFeatureExtractor::ptr ex) : extractor(ex){
}
  virtual Descriptor extract(const DataPoint *dp, RgbImage *visrep = 0) = 0;
  virtual std::string getSpecification() const{ 
   return extractor->getSpecification();
  }
};

} // features
} // vito

#endif
