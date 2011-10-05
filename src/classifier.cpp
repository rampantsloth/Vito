#include "classifier.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;


namespace vito{
namespace classification{

Classifier::~Classifier(){}

void Classifier::train(DataPointCollection dps){
  //DescriptorCollection descriptors = feature->extract(dps);
  //ExampleCollection examples (descriptors, dps.getLabels());
  //train(examples);
}

Classifier::Classifier(boost::shared_ptr<features::IVisualFeatureExtractor > f,
			 std::string n) :
  feature(f), name(n){}

string Classifier::get_name(){
  return name;
}

Label Classifier::classify(DataPoint dp){
  return classify(feature->extract(dp));
}

LabelCollection Classifier::classify(DataPointCollection dp){
  LabelCollection labels;
  labels.reserve(dp.size());
  for(DataPointCollection::iterator i = dp.begin(); i != dp.end(); ++i)
    labels.push_back(classify(*i));
  return labels;
}

LabelCollection Classifier::classify(const DescriptorCollection &descriptors){
  LabelCollection labels;
  labels.resize(descriptors.size());
  for(DescriptorCollection::const_iterator i = descriptors.begin(); 
      i != descriptors.end(); ++i)
    labels.push_back(classify(*i));
  return labels;
}


LabelCollection Classifier::crossvalidation(const ExampleCollection &files){
  // ready CrossValidation Parameters
  const int kFolds = 10;
  const int kFiles = files.size();
  assert(kFolds > 1);

  // fill in results of training/classification on k subgroups
  LabelCollection results(kFiles);
  const float bin_size = kFiles / (float) kFolds;
  for(int subgroup = 0; subgroup < kFolds; ++subgroup){
    const int bin_min = (int) ((bin_size * subgroup) + 0.5);
    const int bin_max = (int) ((bin_size * (subgroup + 1) ) + 0.5);
    ExampleCollection training_set;
    ExampleCollection test_set;
    //fill training and test sets:
    for(int i = 0; i < kFiles; ++i)
      if(i >= bin_min && i < bin_max )
	test_set.push_back(files[i]);
      else
	training_set.push_back(files[i]);

    // train on subgroup
    cout << "crossvalidation is training on " << training_set.size() 
	 << " items"  << endl;
    
    train(training_set); 
    DescriptorCollection test_set_descriptor = (DescriptorCollection) test_set;
    // classify test set
    LabelCollection bin_results = classify(test_set_descriptor); 

    // fill in results of last classification
    for(int i = bin_min; i < bin_max; ++i)
      results[i] = bin_results[i - bin_min];
  }
  return results;
}


Estimation Classifier::estimate(const Descriptor &desc){
  return Estimation(classify(desc));
}


EstimationCollection Classifier::estimate(const DescriptorCollection &desc){
  EstimationCollection estimates;
  estimates.reserve(desc.size());
  for(DescriptorCollection::const_iterator i = desc.begin(); 
      i != desc.end(); ++i)
    estimates.push_back(estimate(*i));
  return estimates;
}


}}

