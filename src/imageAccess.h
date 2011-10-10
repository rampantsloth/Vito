#ifndef IMAGE_ACCES_H
#define IMAGE_ACCES_H

#include "DataPoint.h"
#include "gradient.h"


namespace vito{

/* wrapper to give an image-feature acces to an image without giving
   the image feature acces to the image's location and category
   information */
namespace features{
class CachedFeature;
}

class ImageAccess {
  friend class features::CachedFeature;
protected:
  const DataPoint *datapoint;
public:
  ImageAccess(const DataPoint *dp);

  BwImage                 getBwImage();
  RgbImage                getRgbImage();
  features::ImageGradient getImageGradient();
};

}

#endif
