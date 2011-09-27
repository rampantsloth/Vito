#ifndef PARAMETERDATASOURCE_H
#define PARAMETERDATASOURCE_H

#include <string>

namespace vito{

class ParameterDataSource{
public:
  virtual size_t get(std::string str, size_t original) = 0;
  virtual int    get(std::string str, int original ) = 0;
  virtual double get(std::string str, double original ) = 0;
  virtual bool   get(std::string str, bool original ) = 0;
};

}

#endif
