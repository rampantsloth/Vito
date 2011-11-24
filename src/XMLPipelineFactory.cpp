#include "XMLPipelineFactory.h"
#include "Exceptions.h"
#include "CachedFeatureFetcher.h"
using std::string;

typedef TiXmlNode node;

namespace vito{

using features::CachedFeatureFetcher;
using features::IVisualFeatureExtractor;
using features::FeatureFactory;
using features::IVisualFeatureFetcher;
using classification::Classifier;
using classification::ClassifierAlgorithm;
using classification::BasicClassifier;

ClassifierNode XMLPipelineFactory::buildClassifier(string location){
  TiXmlDocument document(location.c_str());
  if(!document.LoadFile())
    throw exception::FileNotFound();
  node *vitoNode = findChild(&document, "vito");
  node *classifierNode = findChild(vitoNode, "classifier");
  return buildClassifier(classifierNode);
}

ClassifierNode XMLPipelineFactory::buildClassifier(TiXmlNode *classifierNode){
  // build input
  node *inputnode = findChild(classifierNode, "input");
  InputNode input = buildInput(inputnode);
  // build classifier passing the input
  node *clType = 0;
  clType = findChild(classifierNode, "classifierAlgorithm", false);
  if(clType != 0){ // if there is a classifierAlgorithm node
                   // extract a basic classifierAlgorithm
    node * algorithmNode = 0;
    bool done = false;
    ClassifierAlgorithmNode clalg;
    while(!done && (algorithmNode  = clType->IterateChildren(algorithmNode))){
      ParameterDataSource::ptr dsource(new XMLParameterDataSource(clType));
      cout << "just made a dsource with spec: " << dsource->getSpecification() << endl;
      clalg = ClassifierAlgorithmNode(algorithmNode->Value(), dsource);
      done = true;
    }
    return ClassifierNode(input, clalg);
  }
  throw exception::CouldNotCreateClassifier();
  return ClassifierNode();
}


InputNode XMLPipelineFactory::buildInput(node *i){
  node *inputType;
  InputExtractorNode::ptr extractor;
  inputType = findChild(i, "visualFeature", false);
  if(inputType != 0){ // if there is a visualFeature node extract a
		      // basic visualFeature
    node *featureNode = 0;
    bool done = false;
    while(!done && (featureNode = inputType->IterateChildren(featureNode))){
      ParameterDataSource::ptr dsource(new XMLParameterDataSource(inputType));
      extractor = InputExtractorNode::ptr( new VisualFeatureNode(featureNode->Value(), dsource) );
      done = true;
    }
  }else throw exception::XML();
  return InputNode(extractor);
}

}
