#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include "labels.h"
#include <iostream>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include <map>
#include "boost/shared_ptr.hpp"

namespace vito{


/* Descriptor class used to stare image descriptors */
class Descriptor : public std::vector<float>{
public:
  typedef boost::shared_ptr<Descriptor> ptr;
  typedef boost::shared_ptr<const Descriptor> const_ptr;

 private:
  
  friend Descriptor& operator+(Descriptor& left, const Descriptor& right){
    left.insert(left.end(), right.begin(), right.end());
    return left;
  }

 public:

  void operator+=(const Descriptor& other){
    insert(end(), other.begin(), other.end());
  }

  Descriptor() : std::vector<float>(){}
  Descriptor(std::vector<float> a) : std::vector<float>(a){}
  Descriptor(int size) : std::vector<float>(size){}
  void print() const;
  void normalize();
  void normalize(const float min, const float max);
  
  // returns euclidian distance (for now)
  float distance(const Descriptor &b) const; 

};

// Collection structure for both

struct Example{
  const Descriptor *descriptor;
  int label;
  Example(const Descriptor *d, size_t i) : descriptor(d), label(i){}
  Example(const Descriptor &d, size_t i) : descriptor(&d), label(i){}
};

class DescriptorCollection : public std::vector<Descriptor> {
public:
  DescriptorCollection(){}
  DescriptorCollection(size_t size) : std::vector<Descriptor> (size) {}
};


} // namespace vito
#endif
