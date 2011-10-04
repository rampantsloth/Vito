#ifndef IMAGE_H
#define IMAGE_H

#include "geometry.h"
#include <string>
#include "sharedpointer.h"
#include <iostream>
#include <cv.h>
#include <highgui.h>

namespace vito{



typedef struct{
  unsigned char b,g,r;
} RgbPixel;

typedef struct{
  float b,g,r;
} RgbPixelFloat;

/* wraps all opencv functionality */
class OpenCVImage {
protected:
  IplImage *imgp;
public:
  OpenCVImage(IplImage *im) : imgp(im){}
  void blur(int gauss_sizex = 5, int gauss_sizey = 5);
  void drawLine(Point a, Point b, Color pix, size_t thickness);
  void drawBox(Point a, Point b, Color pix, size_t thickness);
};

// C++ wrapper for IplImage
// courtesy of : 
// http://www.cs.iit.edu/~agam/cs512/lect-notes/opencv-intro/opencv-intro.html

template<class T> class Image : public OpenCVImage{
public:
  Image(IplImage *img = 0) : OpenCVImage(img){}
  ~Image(){cvReleaseImage(&imgp);}

  void      operator=(IplImage *img){imgp = img;}
  void      operator=(Image<T> *other){*imgp = *other->imgp;}
  inline T* operator[](const int rowIndx) {
    return ((T *)(imgp->imageData + rowIndx*imgp->widthStep));}

  void   save(std::string loc){cvSaveImage(loc.c_str(),imgp);}
  size_t getHeight() const {return imgp->height;}
  size_t getWidth() const {return imgp->width;}
};

class RgbImage : public Image<RgbPixel>{
public:
  RgbImage(std::string location);
  RgbImage(size_t width, size_t height);
};

class BwImage : public Image<unsigned char>{
public:
  BwImage(std::string location);
  BwImage(size_t width, size_t height);
};

} // vito

#endif
