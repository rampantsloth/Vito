#ifndef PARAMETERDATASOURCE_H
#define PARAMETERDATASOURCE_H

#include <string>
#include <map>
#include "boost/shared_ptr.hpp"

namespace vito{

class ParameterDataSource{
public:
  typedef boost::shared_ptr<ParameterDataSource> ptr;
  typedef boost::shared_ptr<const ParameterDataSource> const_ptr;
private:
  std::map<std::string, std::map< std::string, size_t> > size_ts;
  std::map< std::string, std::map< std::string, bool > > bools;
  std::map< std::string, std::map< std::string, int > > integers;
  std::map< std::string, std::map< std::string, double > > doubles;
public:
  virtual ~ParameterDataSource(){}
  // add/get size_t values
  virtual size_t get(std::string str, std::string parent, size_t original) const;
  virtual void   add(std::string str, std::string parent, size_t value);

  // add/get integer values
  virtual int    get(std::string str, std::string parent, int original ) const;
  virtual void   add(std::string str, std::string parent, int value );

  // add/get  double values
  virtual double get(std::string str, std::string parent, double original ) const;
  virtual void   add(std::string str, std::string parent, double value );

  // add/get bool values
  virtual bool   get(std::string str, std::string parent, bool original ) const;
  virtual void   add(std::string str, std::string parent, bool value );

};

}

#endif
