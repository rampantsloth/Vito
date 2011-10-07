//#define BOOST_TEST_MODULE FileSystem
#include <boost/test/unit_test.hpp>

#include "ParameterDataSourceRecorder.h"


using namespace vito;
using std::vector;

BOOST_AUTO_TEST_CASE(ParameterRecorderTest){
  ParameterDataSource::ptr original( new ParameterDataSource());
  original->add("aap", "muis", 11);
  original->add("aap", "hond", 99);
  ParameterDataSourceRecorder::ptr recorder(new ParameterDataSourceRecorder(original)); 
  BOOST_CHECK(recorder->get("aap", "muis", 0) == 11);
  ParameterDataSource::ptr record = recorder->getRecord();
  BOOST_CHECK(record->get("aap", "muis", 3000) == 11);
  BOOST_CHECK(record->get("aap", "hond", 1313) == 1313);
  BOOST_CHECK(original->get("aap", "muis", 9898) == 11);
  BOOST_CHECK(original->get("aap", "hond", 9898324) == 99);
}
