#ifndef LABELS_H
#define LABELS_H

#include <vector>

namespace vito{

typedef int Label;

class LabelCollection : public std::vector<int>{
public:
  LabelCollection() : std::vector<int>(){}
  LabelCollection(int size) : std::vector<int>(size){}
};

}


#endif 
