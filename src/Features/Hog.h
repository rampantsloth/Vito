#ifndef HOG_H
#define HOG_H

#include "VisualFeatureExtractor.h"
#include "VisualFeatureAlgorithm.h"

namespace vito{
namespace features{

struct HoGWindow {Point topleft, bottomright;};


class HoG : public VisualFeatureAlgorithm{
public:
  struct Parameters {
    bool    blur; // whether to blur or not
    size_t  blur_size; // uneven number to indicate the size of the blur kernel 
    size_t  xhistograms; 
    size_t  yhistograms; // number of gridpoints for histograms on the x and y 
    size_t  orientations; // number of orientations to use creating the histogram
  };
  const Parameters parameters;
public:
  HoG(Parameters p);
  virtual std::string getName(){ return "HoG";}
  virtual Descriptor  extract(ImageAccess image,
			      RgbImage *visrep = 0);
  vector<HoGWindow>   divideIntoWindows(const ImageGradient &gradient,
					RgbImage *visrep);
  Descriptor          calculateHistogram(const HoGWindow &window, 
					 const ImageGradient &gradient,
					 RgbImage *visrep);
  float               wrap(float angle, 
			   const float &min = 0.0, 
			   const float &max = 2.0);
  void                bin(PointGradient gradient, Descriptor *desc);
  void                drawHistogramRepresentation(const HoGWindow &window, 
						  const Descriptor &histogram,
						  RgbImage *visrep); 
}; // HoG


}// features
}// vito

#endif
