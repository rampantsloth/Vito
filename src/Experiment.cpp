#include "Experiment.h"
#include <sstream>

namespace vito{

void Experiment::report(){
  statistics.report();
}

void Experiment::repeat(size_t reps){
  repeat(reps, statistics);
}

void Experiment::repeat(size_t  reps, Statistics &stats){
  for(size_t i = 0; i < reps; i++)
    repeat(stats);
}

void Experiment::repeat(Statistics &stats){
  DataSet::Split split = dataset->split(split_parameters.train, 
					split_parameters.test, 
					split_parameters.equal_representation);
  classifier->train(split.train);
  LabelCollection labels = classifier->classify(split.test);
  stats.addRepetition(split.test, labels);
}

std::string Experiment::getSpecification(){
  std::stringstream ss;
  ss << classifier->getSpecification() 
     << "_on_dataset:_"<< dataset->getSpecification()
     << "_train_size:_"  << split_parameters.train 
     << "_test_size:_" << split_parameters.test;
  if(split_parameters.equal_representation) 
    ss << "_and_equal_representations_of_classes";
  return ss.str();
}

//void Experiment::load(


}
