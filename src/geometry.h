#ifndef GEOMETRY_H
#define GEOMETRY_H

#include<stdlib.h>

struct Color{
  size_t r, g, b;
  Color(size_t r_, size_t g_, size_t b_) : r(r_), g(g_), b(b_){}
};

struct Point{
  size_t x,y;
  Point(size_t a, size_t b) : x(a), y(b){}
  Point() : x(0), y(0){}
};

#endif
