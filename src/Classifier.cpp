#include "Classifier.h"
#include "Exceptions.h"
#include <sstream>

using std::cout;
using std::endl;
using std::vector;

namespace vito{

namespace classification{
 
Classifier::ptr Classifier::Null;

using features::IVisualFeatureFetcher;



Classifier::Classifier(IVisualFeatureFetcher::ptr f): fetcher(f){
}

Classifier::~Classifier(){
}

Label Classifier::classify(const DataPoint *dp){
  return classify(fetcher->extract(dp));
}

LabelCollection Classifier::classify(const dp_refs &dps){
  LabelCollection labels;
  for(dp_refs::const_iterator i = dps.begin(); i != dps.end(); ++i)
    labels.push_back(classify(*i));
  return labels;
}

BasicClassifier::BasicClassifier(IVisualFeatureFetcher::ptr f, 
				 ClassifierAlgorithm::ptr alg) :
  Classifier(f), algorithm(alg){
}

Label   BasicClassifier::classify(Descriptor::const_ptr desc){
  return algorithm->classify(*desc);
}

void BasicClassifier::train(const vector<Example> &examples){
  algorithm->train(examples);
}

std::string BasicClassifier::getSpecification(){
  std::stringstream ss;  
  ss << "classifier_algorithm:_" << algorithm->getSpecification()
     << "_using_input:_" << fetcher->getSpecification();
  return ss.str();
}

void Classifier::train(const DataSet &ds){
  train(ds.getActivePoints());
}

void Classifier::train(const dp_refs &dps){
  if(dps.size() == 0)
    throw exception::NoInput();
  vector<Example> examples = fetcher->extractExamples(dps);
  train( examples );
}

} // classification
} // vito
