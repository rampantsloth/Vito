#include "ParameterDataSource.h"

using std::string;

#define check(type, thing)						\
  if(thing.count(parent))						\
    if(thing.find(parent)->second.count(str))				\
      return (type) thing.find(parent)->second.find(str)->second;
#define order(type, first, second, third, fourth, original)	\
  check(type, first);						\
  check(type, second);						\
  check(type, third);						\
  check(type, fourth);						\
    return original; 

namespace vito{

size_t ParameterDataSource::get(string str, string parent, size_t original) const {
  order(size_t, size_ts, integers, doubles, bools, original);
}
void ParameterDataSource::add(string str, string parent, size_t value){
  size_ts[parent][str] = (int) value;
}

int ParameterDataSource::get(string str, string parent, int original ) const {
  order(int, integers, size_ts, doubles, bools, original);
}
void  ParameterDataSource::add(string str, string parent, int value ){
  integers[parent][str] = value; 
}

double ParameterDataSource::get(string str, string parent, double original ) const {
  order(double, doubles, integers, size_ts, bools, original);
}
void ParameterDataSource::add(string str, string parent, double value ){
    doubles[parent][str] = value; 
}

bool ParameterDataSource::get(string str, string parent, bool original ) const {
  order(bool, bools, integers, size_ts, doubles, original);
}
void ParameterDataSource::add(string str, string parent, bool value )  {
    bools[parent][str] = (int) value; 
}

}
