#include "gradient.h"

namespace vito{
namespace features{

GradientParameters::GradientParameters(){
}

ImageGradient::ImageGradient(BwImage *imagep, 
			     GradientParameters p) :
  Matrix<PointGradient>(imagep->getWidth() - 2, imagep->getHeight() - 2),
  parameters(p)  
{
  BwImage &image = *imagep;
  // for each pixel except the outside pixels:
  for(size_t x = 1; x < image.getWidth() - 1; ++x){
    for(size_t y = 1; y < image.getHeight() - 1; ++y){
      // calculate the orthogonal directions
      double dx = image[x + 1][y] - image[x - 1][y];
      double dy = image[x][y + 1] - image[x][y - 1];
      dx /= 255.0; dy /= 255.0;
      // calculate magnitude of gradient
      at(x - 1, y - 1).magnitude = sqrt(dx * dx + dy * dy);
      // calculate orientation of gradient  
      at(x - 1, y - 1).orientation = atan2(dx, dy);
    }
  }
}

}}
