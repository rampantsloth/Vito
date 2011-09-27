#ifndef GRADIENT_H
#define GRADIENT_H

#include "Image.h"
#include "sharedpointer.h"
#include "matrix.h"

namespace vito{
namespace features{

/* contains all gradient related parameters */
struct GradientParameters{
  GradientParameters();
};

struct PointGradient{
  double magnitude;
  double orientation;
  PointGradient() : magnitude(0.0), orientation(0.0){}
  PointGradient(double m , double o) : magnitude(m), orientation(o){}
};

class ImageGradient : public Matrix<PointGradient>{
private:
  GradientParameters parameters;
public:
  ImageGradient(BwImage *image, 
		GradientParameters parameters = GradientParameters());
};

}}

#endif
