#include "Pipeline.h"
#include "Exceptions.h"
#include "CachedFeatureFetcher.h"

namespace vito{

using std::cout;
using std::endl;
using std::string;
typedef features::FeatureFactory::ptr FeatFactPtr;
typedef classification::ClassifierFactory::ptr ClFactPtr;
typedef classification::ClassifierAlgorithm::ptr ClAlgPtr;
typedef classification::Classifier::ptr ClassifierPtr;
typedef features::IVisualFeatureFetcher::ptr Fetcher;
typedef features::IVisualFeatureExtractor::ptr FeatExtPtr;
typedef features::VisualFeatureAlgorithm::ptr FeatAlgPtr;

// ClassifierAlgorithmNode

ClassifierAlgorithmNode::ClassifierAlgorithmNode(string name, 
						 ParameterDataSource::ptr ds) :
  algorithm_name(name), data_source(ds){
  cout << "currently I just got a parameterdatasource with spec" << ds->getSpecification()<< endl;
}

ClassifierAlgorithmNode::ClassifierAlgorithmNode() : algorithm_name("not_found"),
						     data_source(){
}

ClAlgPtr ClassifierAlgorithmNode::build(ClFactPtr cf){
  if(data_source == 0) throw exception::ClassifierNotFound();
  ClAlgPtr alg = cf->getAlgorithm(algorithm_name, data_source);
  if(alg == 0) throw exception::ClassifierNotFound();
  return alg;
}

// InputNode

InputNode::InputNode(InputExtractorNode::ptr node) : input_extractor(node) {}

InputNode::InputNode() {}

using features::IVisualFeatureFetcher;

features::IVisualFeatureFetcher::ptr InputNode::build(classification::ClassifierFactory::ptr cf, 
						      features::FeatureFactory::ptr ff){
  features::IVisualFeatureFetcher::ptr fetcher(new features::CachedFeatureFetcher( input_extractor->build(cf, ff) ));
  return fetcher;
}

// VisualFeatureNode

VisualFeatureNode::VisualFeatureNode(string name, ParameterDataSource::ptr data_source) : 
  data_source(data_source),
  algorithm_name(name){}


FeatExtPtr VisualFeatureNode::build(ClFactPtr cf, FeatFactPtr ff){
  FeatExtPtr alg = 
    ff->getExtractor(algorithm_name, data_source, 
		     data_source->get(algorithm_name, "stored", true),
		     data_source->get(algorithm_name, "normalized", true));
  if(alg == 0) throw exception::FeatureNotFound();
  return alg;
}

// ClassifierNode

ClassifierNode::ClassifierNode(){}

ClassifierNode::ClassifierNode(InputNode inp, ClassifierAlgorithmNode cl_alg) :
  input(inp), classifier_algorithm(cl_alg){}

ClassifierPtr ClassifierNode::build(FeatFactPtr ff, ClFactPtr cf){
  features::IVisualFeatureFetcher::ptr feat_fetch = input.build(cf, ff);
  ClAlgPtr class_alg = classifier_algorithm.build(cf);
  classification::Classifier::ptr classifier( new classification::BasicClassifier( feat_fetch, class_alg) );
  if(classifier == 0) throw exception::FeatureNotFound();
  return classifier;
}


}
