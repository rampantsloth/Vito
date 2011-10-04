#include "HoG.h"

#define PI 3.14159265

namespace vito{
namespace features{

HoG::HoG(HoGParameters p) : parameters(p){}

Descriptor HoG::extract(ImageAccess image,
			RgbImage *visrep){
  BwImage bwim = image.getBwImage();   // use black and white
  if(parameters.blur)   // blur the image
    bwim.blur(parameters.blur_size, parameters.blur_size);
  // get the image gradient
  const ImageGradient gradient(&bwim, GradientParameters());
  // decide how many windows to create
  const vector<HoGWindow> windows = divideIntoWindows(gradient, visrep); 
  Descriptor descriptor;
  descriptor.reserve(windows.size() * parameters.orientations);
  // create a histogram for each window
  for(vector<HoGWindow>::const_iterator i = windows.begin(); 
      i != windows.end(); ++i)
    descriptor += calculateHistogram(*i, gradient, visrep);
  //TODO check whether descriptor meets length and return it
  return descriptor;
}

Descriptor HoG::calculateHistogram(const HoGWindow &window, 
				   const ImageGradient &gradient,
				   RgbImage *visrep){
  // bin each pixel to a bin for each orientation
  Descriptor histogram(parameters.orientations);
  for(size_t x = window.topleft.x; x < window.bottomright.x; x++)
    for(size_t y = window.topleft.y; y < window.bottomright.y; y++)
      bin(gradient(x,y), &histogram);
  drawHistogramRepresentation(window, histogram, visrep);
  return histogram;
}

//void bin(Gradient &gradient, Descriptor &bin_values, const float &multiplier){
void HoG::bin(PointGradient gradient, Descriptor *bin_values){
  float angle = gradient.orientation / PI;
  float bin_size = 2.0 / parameters.orientations;
  float angle_min = angle - (0.5 * bin_size);
  float angle_max = angle + (0.5 * bin_size);
  
  angle_min = wrap(angle_min);
  angle_max = wrap(angle_max);

  cout << "min: " << angle_min << " max: " << angle_max << endl;

  float bin_min;
  float bin_max = 0;
  for(size_t bin = 0; bin < bin_values->size(); ++bin){
    bin_min = bin_max;
    bin_max = (bin + 1) * bin_size;
    float share; // the magnitude of the share of the gradient falling
		 // within the bin
    if(angle_min >= bin_min && angle_min <= bin_max){
      share = ((bin_max - angle_min) / bin_size);
      bin_values->at(bin) += share * gradient.magnitude;
    }
    else if(angle_max >= bin_min && angle_max <= bin_max){
      share = ((angle_max - bin_min) / bin_size);
      bin_values->at(bin) += share * gradient.magnitude;   
    }
  }
}

float HoG::wrap(float angle, const float &min, const float &max){
  float period = max - min;
  while(angle < min || angle > max){
    if(angle > max)
      angle -= period;
    else if(angle < min)
      angle += period;
  }
  return angle;
}


vector<HoGWindow> HoG::divideIntoWindows(const ImageGradient &gradient,
				       RgbImage *visrep){
  vector<HoGWindow> windows;
  windows.reserve(parameters.xhistograms * parameters.yhistograms);
  // create windows evenly and without overlap
  size_t window_height = gradient.get_height() / parameters.xhistograms;
  size_t window_width = gradient.get_width() / parameters.yhistograms;
  for(size_t x = 0; x < parameters.xhistograms; ++x)
    for(size_t y = 0; y < parameters.yhistograms; ++y){
      HoGWindow window;
      window.topleft.x = x * window_width;
      window.topleft.y = y * window_height;
      window.bottomright.x = (x + 1) * window_width;
      window.bottomright.y = (y + 1) * window_height;
      windows.push_back(window);
      cout << "window at: topleft: " << window.topleft.x << "*" << window.topleft.y
	   <<" and botrights: " << window.bottomright.x << "*" << window.bottomright.y << endl;
      if(visrep != 0){
	visrep->drawBox(Point(window.topleft.x, window.topleft.y),
		       Point(window.bottomright.x, window.bottomright.y),
		       Color(255,0,0), 1);
      }
    }
  return windows;
}

void HoG::drawHistogramRepresentation(const HoGWindow &w,
				      const Descriptor &histogram, 
				      RgbImage *visrep){
  double bin_size  = 2 * PI / parameters.orientations;
  size_t window_pixels = 
    (w.bottomright.x - w.topleft.x) * (w.bottomright.y - w.topleft.y);
  Point center((w.bottomright.x -  w.topleft.x) / 2 + w.topleft.x,
	       (w.bottomright.y - w.topleft.y) / 2 + w.topleft.y);
  size_t radius = min(w.bottomright.x - w.topleft.x, 
		      w.bottomright.y - w.topleft.y) / 2;
  double magnification = 205 * radius / (double) window_pixels;
  cout << "magnification" << magnification << endl;
  for(Descriptor::const_iterator i = histogram.begin();
      i != histogram.end(); ++i){
    double bin_angle = (bin_size * (i - histogram.begin() + 1)) -
      (0.5 * bin_size);
    cout << bin_angle << " is the bin angle " << endl;
    Point target(center.x + *i * magnification * cos(bin_angle),
		 center.y + *i * magnification * sin(bin_angle));
    visrep->drawLine(center, target, Color(0,255,0), 1);
  }
}

}// features
}// vito
