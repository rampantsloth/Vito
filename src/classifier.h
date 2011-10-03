#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "sharedpointer.h"
#include "estimation.h"
#include "labels.h"
#include "descriptor.h"
#include <assert.h>
#include "VisualFeatureExtractor.h"


namespace vito{
namespace classification{

/* Abstract class that  contains a feature to use */
class Classifier{
private:
  boost::shared_ptr<features::IVisualFeatureExtractor> feature;
  std::string           name;

public:
  Classifier(boost::shared_ptr<features::IVisualFeatureExtractor> feature, std::string name);

  // pure methods
  virtual std::string      get_name();

  

  void                     train(DataPointCollection dps);
  virtual void             train(ExampleCollection dp) = 0;

  Label                    classify(DataPoint dp);
  LabelCollection          classify(DataPointCollection dp);

  virtual Label            classify(const Descriptor &descriptor ) = 0;
  LabelCollection          classify(const DescriptorCollection &descriptors);

  virtual Estimation       estimate(const Descriptor &descriptor );
  EstimationCollection     estimate(const DescriptorCollection &descriptors);
  
  // non-virtual generic methods
  LabelCollection          crossvalidation(const ExampleCollection &files);
};
  
}}

#endif

