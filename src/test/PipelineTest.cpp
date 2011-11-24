#include <boost/test/unit_test.hpp>


#include "XMLPipelineFactory.h"
#include "BoostFileSystem.h"
#include "Experiment.h"


using namespace vito;
using namespace vito::classification;
using namespace vito::features;

BOOST_AUTO_TEST_CASE(TestPipeLineCreator){ 
  FileSystem::ptr fs (new BoostFileSystem());
  FeatureFactory::ptr ff( new FeatureFactory(fs, "obj/ClassifierPlugins"));
  ClassifierFactory::ptr cf(new ClassifierFactory(fs, "obj/FeaturePlugins"));
  XMLPipelineFactory pipf;
  ClassifierNode classifier_node = pipf.buildClassifier("pipeline.xml");
  Classifier classifier = classifier_node.build(ff, cf);
  DataSet ds("./datasets/caltech101" ,fs);
  ds.setCategoryActivity("Motorbikes", true);
  ds.setCategoryActivity("airplanes", true);
  DataSet::Split split = ds.split();
  cl->train(ds);
}
