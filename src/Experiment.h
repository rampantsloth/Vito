#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "Classifier.h"
#include "Statistics.h"

namespace vito{

class Experiment{
public:
  struct SplitParameters{
    size_t train;
    size_t test;
    bool equal_representation;
    SplitParameters(size_t trn, size_t tst, bool eqrep = true) 
      : train(trn), test(tst), equal_representation(eqrep) {};
  };
private:
  classification::Classifier::ptr classifier;
  DataSet::ptr                    dataset;
  SplitParameters                 split_parameters;
  Statistics                      statistics;
public:
  Experiment(classification::Classifier::ptr cl, DataSet::ptr ds, SplitParameters sp) :
    classifier(cl), dataset(ds), split_parameters(sp){}
  void repeat(size_t reps = 1);
  void repeat(size_t reps, Statistics &stats);
  void repeat(Statistics &stats);
  void save();
  void load();
  void report();
  std::string getSpecification();

};

}

#endif
