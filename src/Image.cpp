#include "Image.h"

namespace vito{

using std::string;
using std::cout;
using std::endl;

void OpenCVImage::drawLine(Point a, Point b, Color pix, size_t thickness){
  cvLine(imgp, cvPoint(a.x,a.y), cvPoint(b.x,b.y), 
	 cvScalar(pix.r, pix.g, pix.b), thickness);
}

void OpenCVImage::drawBox(Point a, Point b, Color pix, size_t thickness){
  cvRectangle(imgp, cvPoint(a.x,a.y), cvPoint(b.x,b.y), 
	 cvScalar(pix.b, pix.g, pix.r), thickness);
}

void OpenCVImage::blur(int gauss_sizex, int gauss_sizey){
  //blur kernel must be uneven
  if(gauss_sizex % 2 == 0)
    gauss_sizex++;
  if(gauss_sizey % 2 == 0)
    gauss_sizey++;
  cvSmooth(imgp, imgp, CV_GAUSSIAN, gauss_sizex, gauss_sizey);
}

RgbImage::RgbImage(size_t width, size_t height) :
  Image<RgbPixel>(cvCreateImage(cvSize(width,height),IPL_DEPTH_8U,3)){
  if (imgp == 0)
    cout << "Image was not created" << endl;
}

RgbImage::RgbImage(string location) : 
  Image<RgbPixel>(cvLoadImage(location.c_str(),1)){
  if(imgp == 0)
    cout << "Image " << location << " failed to load" << endl;
}

BwImage::BwImage(std::string location) :
  Image<unsigned char>(cvLoadImage(location.c_str(), 0)){
  if(imgp == 0)
        cout << "Image " << location << " failed to load" << endl;
}

BwImage::BwImage(size_t width, size_t height) :
  Image<unsigned char>(cvCreateImage(cvSize(width,height),IPL_DEPTH_8U,1)){
  if (imgp == 0)
    cout << "Image was not created" << endl;
}

}
