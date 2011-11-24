#ifndef SVMClassifier_H
#define SVMClassifier_H

#include "ClassifierAlgorithm.h"
#include "svm.h"

namespace vito{
namespace classification{

class SVMClassifier : public ClassifierAlgorithm{
public:
  typedef svm_parameter Parameters;  
  virtual std::string getSpecification();
  virtual ~SVMClassifier();
  SVMClassifier(Parameters pars); 
  virtual Label classify(const Descriptor &descriptor) const;
  virtual void  train(const std::vector<Example> &examples);
private:  
  Parameters   parameters; 
  svm_model   *model;
  svm_problem *prblm;

  void         svm_destroy_problem(svm_problem **problem);
  svm_problem *compileProblem(const std::vector<Example> &examples);
  svm_node    *constructNode(const Descriptor &descriptor) const;
  void         addExampleToProblem(svm_problem  *problem_, 
				   const Example &example);
};

/*As of yet unweighed */
class CSVC_RBF_Classifier : public SVMClassifier{
public:
  virtual std::string getName(){return "SVM";}
  typedef boost::shared_ptr<CSVC_RBF_Classifier> ptr;
  struct Parameters{
    int    shrinking, probability, cache_size;
    double  epsilon, C, gamma;
    operator SVMClassifier::Parameters(){
      SVMClassifier::Parameters svm_p = {C_SVC, RBF, 0, // degree
					 gamma, 0, //coef0 
					 cache_size, epsilon, C, 
					 0, //nr_weight
					 0, // weight
					 0, // Nu
					 0, // epsilon
					 shrinking, probability};
      return svm_p;
    }
  };
  CSVC_RBF_Classifier(Parameters p) : SVMClassifier(p){}
private:
  Parameters csvc_parameters;
};

}// SVM
}// vito

#endif
