#ifndef PARAMETERDATASOURCERECORDER _H
#define PARAMETERDATASOURCERECORDER _H

#include "ParameterDataSource.h"

namespace vito{

class ParameterDataSourceRecorder : public ParameterDataSource{
public:
  typedef boost::shared_ptr<ParameterDataSourceRecorder> ptr;
private:
  ParameterDataSource::ptr true_source;
  ParameterDataSource::ptr record;
public:
  ParameterDataSource::ptr getRecord(){
    return record;
  }
  virtual std::string getSpecification();

  ParameterDataSourceRecorder(ParameterDataSource::ptr orig):
    true_source(orig), record(new ParameterDataSource()) {
  }

  ParameterDataSourceRecorder(ParameterDataSource::ptr original_,
			      ParameterDataSource::ptr reccord_) :
    true_source(original_), record(reccord_) {}


  virtual ~ParameterDataSourceRecorder(){}
  // add/get size_t values
  virtual size_t get(std::string str, std::string parent, size_t original) ;
  virtual void   add(std::string str, std::string parent, size_t value);

  // add/get integer values
  virtual int    get(std::string str, std::string parent, int original ) ;
  virtual void   add(std::string str, std::string parent, int value );

  // add/get  double values
  virtual double get(std::string str, std::string parent, double original ) ;
  virtual void   add(std::string str, std::string parent, double value );

  // add/get bool values
  virtual bool   get(std::string str, std::string parent, bool original ) ;
  virtual void   add(std::string str, std::string parent, bool value );
};

}

#endif
