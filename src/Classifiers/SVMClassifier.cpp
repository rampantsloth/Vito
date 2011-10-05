#include "SVMClassifier.h"

using std::cout;
using std::endl;

namespace vito{
namespace classification{


SVMClassifier::~SVMClassifier(){}

SVMClassifier::SVMClassifier(Parameters pars) : 
  parameters(pars){
#define print(dummy) cout << #dummy " = " << parameters.dummy << endl;
  print(svm_type);
  print(kernel_type);
  print(gamma);
  print(C);
} 

void SVMClassifier::svm_destroy_problem(svm_problem **problem_){
  svm_problem * problem = *problem_;
  delete [] problem->y;
  problem->y = 0;
  for(int i = 0; i < problem->l; ++i){
    delete [] problem->x[i];
    problem->x[i] = 0;
  }
  delete [] problem->x;
  problem->x = 0;
  problem_ = 0;
}

void SVMClassifier::train(ExampleCollection examples){
  // destroy any existing models
  if(!model){
    svm_free_and_destroy_model(&model);
    cout << "SVMFREE AND DESTROY IS WORKING PROPERLY IF 0 == " << model << endl;
    model = 0; // hopefully already done in prefious function
  }
  // destroy any existing problems
  if(!prblm)
    svm_destroy_problem(&prblm);
  // train!
  prblm = compileProblem(examples);
  model = svm_train(prblm, &parameters);
}

Label SVMClassifier::classify(const Descriptor &descriptor) const{
 svm_node *nodes = constructNode(descriptor);
  //print::print_svm_nodes(nodes, descriptor.size());
  double   result = svm_predict(model, nodes);
  //vector<double> value_per_class = getValues(nodes, model);
  /*
  typedef Descriptor::const_iterator desit;
  cout << "descriptor: ";
  for(desit i = descriptor.begin(); i != descriptor.end(); ++i){
    if((i - descriptor.begin()) % 10 == 0)
      cout << endl;
    cout << *i << " ";
  }
  cout << endl << "result: " << result << endl;
  */
  delete [] nodes;
  return result;
}

svm_problem* SVMClassifier::compileProblem(const ExampleCollection &examples){
  // check if there are 1 or more examples to train on
  const int& kExamples = examples.size();
  if(kExamples < 1){
    printf("Need datapoints for training...\n");
    return NULL;
  }
  // allocate a problem
  svm_problem *problem_ = new svm_problem;
  svm_problem &problem = *problem_;
  problem.l = 0; // l will increment by adding each example
  problem.y = new double[kExamples]; // labels
  problem.x = new svm_node*[kExamples]; // datapoints
  // add every example to our newly allocated svm_problem
  for(ExampleCollection::const_iterator i = examples.begin();
      i != examples.end(); ++i)
    addExampleToProblem(problem_, *i);
  return problem_;
}

void SVMClassifier::addExampleToProblem(svm_problem *problem, 
					const Example &example){
  problem->y[problem->l] = (double) example.get_label();
  problem->x[problem->l] = constructNode(example);
  problem->l++;
}

svm_node* SVMClassifier::constructNode(const Descriptor &descriptor) const {
  svm_node *nodes = new svm_node[descriptor.size() + 1];
  Descriptor::const_iterator it = descriptor.begin();
  for(int i = 0; it != descriptor.end();++it, ++i){
    nodes[i].value = *it;
    nodes[i].index = i;
  }
  nodes[descriptor.size()].value = 0.0;
  nodes[descriptor.size()].index = -1; 
  return nodes;
}

}// classification
}// vito