#ifndef PARAMETERDATASOURCE_H
#define PARAMETERDATASOURCE_H

#include <string>
#include <map>

namespace vito{

class ParameterDataSource{
private:
  std::map<std::string, std::map< std::string, size_t> > size_ts;
  std::map< std::string, std::map< std::string, bool > > bools;
  std::map< std::string, std::map< std::string, int > > integers;
  std::map< std::string, std::map< std::string, double > > doubles;
public:

  // add/get size_t values
  virtual size_t get(std::string str, std::string parent, size_t original);
  virtual void   add(std::string str, std::string parent, size_t value);

  // add/get integer values
  virtual int    get(std::string str, std::string parent, int original );
  virtual void   add(std::string str, std::string parent, int value );

  // add/get  double values
  virtual double get(std::string str, std::string parent, double original );
  virtual void   add(std::string str, std::string parent, double value );

  // add/get bool values
  virtual bool   get(std::string str, std::string parent, bool original );
  virtual void   add(std::string str, std::string parent, bool value );

};

}

#endif
