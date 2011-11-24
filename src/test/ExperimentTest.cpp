//#define BOOST_TEST_MODULE FileSystem
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <vector>
#include "BoostFileSystem.h"
#include "DataSet.h"
#include "Experiment.h"
#include "XMLPipelineFactory.h"

using namespace vito;
using namespace vito::classification;
using namespace vito::features;
using std::vector;

BOOST_AUTO_TEST_CASE(ExperimentTest){
  FileSystem::ptr fs( new BoostFileSystem() );
  FeatureFactory::ptr ff( new FeatureFactory(fs, "obj/ClassifierPlugins/"  ));
  ClassifierFactory::ptr cf( new ClassifierFactory(fs, "obj/FeaturePlugins/" ));
  XMLPipelineFactory xmlpf(ff, cf);
  Classifier::ptr classifier = xmlpf.buildClassifier("pipeline.xml");
  DataSet::ptr dataset(new DataSet("datasets/caltech101", fs));
  dataset->activate("airplanes");
  dataset->activate("Motorbikes");
  Experiment::SplitParameters split(30, 30);
  Experiment experiment(classifier, dataset, split);
  experiment.repeat(10);
  experiment.report();
}
