#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "ClassifierAlgorithm.h"
#include "IVisualFeatureFetcher.h"

namespace vito{
namespace classification{

class Classifier{
private:
  features::IVisualFeatureFetcher::ptr fetcher;
public:
  Classifier(features::IVisualFeatureFetcher::ptr f);
  virtual      ~Classifier();
          Label classify(const DataPoint *dp);
  virtual Label classify(const Descriptor * desc) = 0;  
  virtual void  train(const std::vector<Example> &examples) = 0;
};

class BasicClassifier : public Classifier{
private:
  ClassifierAlgorithm::ptr algorithm;
public:
                 BasicClassifier(features::IVisualFeatureFetcher::ptr f, 
				ClassifierAlgorithm::ptr algorithm);
  virtual Label classify(const Descriptor * desc);

};

}}

#endif
