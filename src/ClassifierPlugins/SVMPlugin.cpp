#include "ClassifierPlugin.h"
#include "SVMClassifier.h"
#include "ParameterDataSource.h"

using vito::classification::ClassifierAlgorithm;
using vito::classification::CSVC_RBF_Classifier;
using vito::ParameterDataSource;

extern "C"{

  ClassifierAlgorithm::ptr makeSVM(vito::ParameterDataSource::const_ptr source){
#define set(dummy) parameters.dummy = source->get("HoG", #dummy, parameters.dummy);
    CSVC_RBF_Classifier::Parameters parameters;
    set(shrinking);
    set(probability);
    set(cache_size);
    set(epsilon);
    set(C);
    set(gamma);
    
  };
 class Initializer{
  public:
    Initializer(){
      classifier_factory["SVM"] = makeSVM;
  }
  };
  Initializer p;
}
