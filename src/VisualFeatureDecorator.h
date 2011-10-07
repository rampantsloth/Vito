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
  virtual Descriptor extract(DataPoint dp, RgbImage *visrep = 0) = 0;
  virtual std::string getName(){
    return "stored_" + extractor->getName();
  }
};

} // features
} // vito

#endif
