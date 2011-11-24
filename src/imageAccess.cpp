#include "imageAccess.h"

#include "BoostFileSystem.h"
#include "Exceptions.h"

namespace vito{

ImageAccess::ImageAccess(const DataPoint *dp) : datapoint(dp){
  BoostFileSystem fs;
  if(!fs.exists(dp->getURL()))
    throw exception::FileNotFound();
}

BwImage ImageAccess::getBwImage(){
  return BwImage(datapoint->getURL());
}

RgbImage ImageAccess::getRgbImage(){
  return RgbImage(datapoint->getURL());
}

features::ImageGradient ImageAccess::getImageGradient(){
  BwImage bw(datapoint->getURL());
  return features::ImageGradient(&bw, features::GradientParameters());
}

}
