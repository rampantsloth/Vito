#ifndef SVMClassifier_H
#define SVMClassifier_H

#include "svm.h"
#include "classifier.h"

namespace vito{
namespace classification{

struct SVMClassifierParameters{
};

class SVMClassifier : public Classifier {
private:
  SVMClassifierParameters parameters;
  svm_model *model;
  svm_problem *prblm;

  svm_problem *  compileProblem(const ExampleCollection &examples);
public:
  SVMClassifier(SVMClassifierParameters pars, 
      SP<features::IVisualFeatureExtractor> feat);
  virtual Label classify(const Descriptor &descriptor);
  virtual void  train(ExampleCollection dp);
};

}}

#endif
