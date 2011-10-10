#include "ClassifierPlugin.h"
#include "SVMClassifier.cpp"
#include "ParameterDataSource.h"
#include <iostream>

using vito::classification::ClassifierAlgorithm;
using vito::classification::CSVC_RBF_Classifier;
using vito::ParameterDataSource;

extern "C"{
  
  ClassifierAlgorithm::ptr makeSVM(vito::ParameterDataSource::ptr source){
#define set(dummy, std) parameters.dummy = source->get("SVM", #dummy, std);
    CSVC_RBF_Classifier::Parameters parameters;
    set(shrinking, 0);
    set(probability, 0);
    set(cache_size, 1024);
    set(epsilon, 0.64);
    set(C, 200);
    set(gamma, 0.2);
    ClassifierAlgorithm::ptr alg(new CSVC_RBF_Classifier(parameters));  
    return alg;
  }
  
  
 class SVMInitializer{
  public:
    SVMInitializer(){
      std::cout << "adding SVM" << std::endl;
      classifier_factory["SVM"] = makeSVM;
    }
  };
  SVMInitializer p;
  
  int bla(){return 0;}
}
