#ifndef PIPELINE_H
#define PIPELINE_H

#include "Classifier.h"
#include "FeatureFactory.h"
#include "ClassifierFactory.h"
#include "FeatureFactory.h"
#include "ParameterDataSource.h"


namespace vito{


class ClassifierAlgorithmNode{
  std::string algorithm_name;
  ParameterDataSource::ptr data_source;
public:
  ClassifierAlgorithmNode(std::string name, ParameterDataSource::ptr ds);
  ClassifierAlgorithmNode();
  classification::ClassifierAlgorithm::ptr build(classification::ClassifierFactory::ptr cf);
};

class InputExtractorNode{
public:
  typedef features::IVisualFeatureExtractor::ptr FeatExtPtr;
  typedef boost::shared_ptr<InputExtractorNode> ptr;
  virtual FeatExtPtr build(classification::ClassifierFactory::ptr cf,
			   features::FeatureFactory::ptr ff) = 0;
};

class InputNode{
protected:
  InputExtractorNode::ptr input_extractor;
public:
  features::IVisualFeatureFetcher::ptr build(classification::ClassifierFactory::ptr cf, 
					     features::FeatureFactory::ptr ff);
  InputNode();
  InputNode(InputExtractorNode::ptr node);
};


class VisualFeatureNode : public InputExtractorNode{
  ParameterDataSource::ptr data_source;
  std::string algorithm_name;
public:
  VisualFeatureNode(std::string str, ParameterDataSource::ptr data_source);
  virtual FeatExtPtr build(classification::ClassifierFactory::ptr cf,
			   features::FeatureFactory::ptr ff);
};



class ClassifierNode{
  InputNode input;
  ClassifierAlgorithmNode classifier_algorithm;
public:
  ClassifierNode();
  ClassifierNode(InputNode inp, ClassifierAlgorithmNode cl_alg);
  classification::Classifier::ptr build(features::FeatureFactory::ptr ff, 
					classification::ClassifierFactory::ptr cf);
};
}


#endif
