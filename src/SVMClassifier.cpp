#include "SVMClassifier.h"

namespace vito{
namespace classification{


SVMClassifier::SVMClassifier(SVMClassifierParameters pars, 
	 SP<features::IVisualFeatureExtractor> feat) : 
  Classifier(feat, "SVMClassifier"), 
  parameters(pars){}

void SVMClassifier::train(ExampleCollection dp){
  
}

Label SVMClassifier::classify(const Descriptor &descriptor){

}

svm_problem* SVMClassifier::compileProblem(const ExampleCollection &examples){
  // check if there are 1 or more examples to train on
  const int& kExamples = examples.size();
  if(kExamples < 1){
    printf("Need datapoints for training...\n");
    return NULL;
  }
  svm_problem *problem_ = new svm_problem;
  svm_problem &problem = *problem_;
  problem.l = 0; 
  problem.y = new double[kExamples]; // labels
  problem.x = new svm_node*[kExamples]; // datapoints
  // add every example to our newly allocated svm_problem
  //for(size_t i = 0; (int) i < kExamples; ++i)
  //addExampleToProblem(problem, examples[i]);
  return &problem;
}

}// classification
}// vito
