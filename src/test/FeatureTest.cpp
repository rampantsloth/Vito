#define BOOST_TEST_MODULE Features
#include <boost/test/unit_test.hpp>

#include "FeatureFactory.h"
#include "BoostFileSystem.h"
#include "XMLParameterDataSource.h"


using namespace vito::features;
using namespace vito;

BOOST_AUTO_TEST_CASE(TestFeatureFetcher){
  FileSystem::ptr system( new BoostFileSystem());
  std::string file = "../VisionTool/datasets/caltech101/flamingo/image_0001.jpg";
  ParameterDataSource::ptr dsource(new XMLParameterDataSource ("parameters.xml"));
  FeatureFactory factory(system, FEATUREPLUGINDIR);
  IVisualFeatureExtractor::ptr hog = factory.getExtractor("HoG", dsource);
  std::cout << hog->getSpecification() << std::endl;
  std::cout << dsource->getSpecification() << std::endl;
  hog->extract(DataPoint(0,"image_0001.jpg", file,file));
  //IVisualFeatureFetcher::ptr ho4 = factory.getFetcher("HoG", true, true);

}
