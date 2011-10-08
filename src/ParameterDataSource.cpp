#include "ParameterDataSource.h"
#include <sstream>
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
  add(parent, str, (type) original);				\
  return original; 

namespace vito{

size_t ParameterDataSource::get(string parent, string str, size_t original) {
  order(size_t, size_ts, integers, doubles, bools, original);
}
void ParameterDataSource::add(string parent, string str, size_t value){
  size_ts[parent][str] = (int) value;
}

int ParameterDataSource::get(string parent, string str, int original ) {
  order(int, integers, size_ts, doubles, bools, original);
}
void  ParameterDataSource::add(string parent, string str, int value ){
  integers[parent][str] = value; 
}

double ParameterDataSource::get(string parent, string str, double original ) {
  order(double, doubles, integers, size_ts, bools, original);
}
void ParameterDataSource::add(string parent, string str, double value ){
    doubles[parent][str] = value; 
}

bool ParameterDataSource::get(string parent, string str, bool original ) {
  order(bool, bools, integers, size_ts, doubles, original);
}
void ParameterDataSource::add(string parent, string str, bool value )  {
    bools[parent][str] = (int) value; 
}

string ParameterDataSource::getSpecification(){
  std::stringstream ss;
#define addspecs(type, object)						\
  for ( std::map<std::string, std::map< std::string, type> >::iterator i = \
	  object.begin(); i != object.end(); ++i){			\
    for( std::map< std::string, type>::iterator j = i->second.begin();	\
	 j != i->second.end(); ++j)					\
      ss << i->first << "(" << j->first << "=" << j->second << ")_";	\
    }		
  addspecs(size_t, size_ts);
  addspecs(int, integers);
  addspecs(bool, bools);
  addspecs(double, doubles);
  return ss.str();
}
}
