#define BOOST_TEST_MODULE Features
#include <boost/test/unit_test.hpp>

#include "ClassifierFactory.h"
#include "BoostFileSystem.h"
#include "XMLParameterDataSource.h"

using namespace vito::features;
using namespace vito;

BOOST_AUTO_TEST_CASE(TestFeatureFetcher){
  FileSystem::ptr system( new BoostFileSystem());
  ParameterDataSource::ptr dsource(new XMLParameterDataSource ("parameters.xml"));
  FeatureFactory factory(system, dsource, FEATUREPLUGINDIR);
  IVisualFeatureExtractor::ptr hog = factory.getExtractor("HoG", true, true);
  IVisualFeatureExtractor::ptr hog1 = factory.getExtractor("HoG", true, false);
  IVisualFeatureExtractor::ptr hog2 = factory.getExtractor("HoG", false, true);
  IVisualFeatureExtractor::ptr hog3 = factory.getExtractor("HoG", false, false);
  IVisualFeatureFetcher::ptr ho4 = factory.getFetcher("HoG", true, true);

}
