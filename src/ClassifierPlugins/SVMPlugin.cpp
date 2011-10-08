#include "ClassifierPlugin.h"
#include "SVMClassifier.h"
#include "ParameterDataSource.h"

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
    return ClassifierAlgorithm::ptr(new CSVC_RBF_Classifier(parameters));  
  };
 class SVMInitializer{
  public:
    SVMInitializer(){
      classifier_factory["SVM"] = makeSVM;
    }
  };
  SVMInitializer p;
}
