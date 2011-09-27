#ifndef IMAGE_ACCES_H
#define IMAGE_ACCES_H

#include "dataPoint.h"
#include "gradient.h"


namespace vito{

/* wrapper to give an image-feature acces to an image without giving
   the image feature acces to the image's location and category
   information */
namespace features{
class CachedFeature;
}

class ImageAccess : private DataPoint{

  friend class features::CachedFeature;

public:
  ImageAccess(DataPoint dp);

  BwImage                 getBwImage();
  RgbImage                getRgbImage();
  features::ImageGradient getImageGradient();
};

}

#endif
