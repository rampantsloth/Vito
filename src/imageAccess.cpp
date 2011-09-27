#include "imageAccess.h"

namespace vito{

ImageAccess::ImageAccess(DataPoint datapoint) : DataPoint(datapoint){}

BwImage ImageAccess::getBwImage(){
  return BwImage(get_image_url());
}

RgbImage ImageAccess::getRgbImage(){
  return RgbImage(get_image_url());
}

features::ImageGradient ImageAccess::getImageGradient(){
  BwImage bw(get_image_url());
  return features::ImageGradient(&bw, features::GradientParameters());
}

}
