#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Classifiers
#include <boost/test/unit_test.hpp>
 

#include "ClassifierFactory.h"
#include "BoostFileSystem.h"
#include "XMLParameterDataSource.h"


using namespace vito::classification;
using namespace vito;

BOOST_AUTO_TEST_CASE(TestSVM){
  FileSystem::ptr system( new BoostFileSystem());
  ParameterDataSource::ptr dsource(new XMLParameterDataSource ("parameters.xml"));
  ClassifierFactory factory(system, dsource, CLASSIFIERPLUGINDIR);
  ClassifierAlgorithm::ptr calg = factory.getAlgorithm("SVM");
  BOOST_CHECK(calg != 0);
#define makevector(name, v1,v2,v3,v4)		\
  Descriptor name;				\
  name.push_back(v1);				\
  name.push_back(v2);				\
  name.push_back(v3);				\
  name.push_back(v4);
  makevector(a1,0.1, 0.2, 0.63, 0.21);
  makevector(a2,0.2, 0.22, 0.43, 0.14);
  makevector(a3,0.4, 0.24, 0.33, 0.31);
  makevector(a4,0.02 ,0.25, 0.13, 0.12);
  makevector(b1,0.61, 0.72, 0.863, 0.821);
  makevector(b2,0.72, 0.522, 0.943, 0.914);
  makevector(b3,0.94, 0.924, 0.733, 0.831);
  makevector(b4,0.602 ,0.725, 0.7013, 0.712);
  ExampleCollection col;
  col.push_back(Example(a1,2));
  col.push_back(Example(a2,2));
  col.push_back(Example(a3,2));
  col.push_back(Example(a4,2));
  col.push_back(Example(b1,4));
  col.push_back(Example(b2,4));
  col.push_back(Example(b3,4));
  col.push_back(Example(b4,4));
  calg->train(col);
  calg->train(col);
  calg->train(col);
  BOOST_CHECK(calg->classify(a1) == 2);
  BOOST_CHECK(calg->classify(b1) == 4);
  BOOST_CHECK(calg->classify(a2) == 2);
  BOOST_CHECK(calg->classify(b2) == 4);
  BOOST_CHECK(calg->classify(a3) == 2);
  BOOST_CHECK(calg->classify(b3) == 4);
  BOOST_CHECK(calg->classify(a4) == 2);
  BOOST_CHECK(calg->classify(b4) == 4);
  makevector(a5, 0.123, 0.54, 0.23, 0.43);
  makevector(b5, 0.5123, 0.654, 0.823, 0.943);
  BOOST_CHECK(calg->classify(a5) == 2);
  BOOST_CHECK(calg->classify(b5) == 4);
}
