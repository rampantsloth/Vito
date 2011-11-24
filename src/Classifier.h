#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "ClassifierAlgorithm.h"
#include "IVisualFeatureFetcher.h"
#include "Dataset.h"

namespace vito{
namespace classification{

class Classifier{
public:
  typedef features::IVisualFeatureFetcher::dp_refs dp_refs;
  typedef boost::shared_ptr<Classifier> ptr;
  static Classifier::ptr Null;
  Classifier(features::IVisualFeatureFetcher::ptr f);
  virtual           ~Classifier();
          Label      classify(const DataPoint *dp);
  virtual Label      classify(Descriptor::const_ptr desc) = 0;
  LabelCollection    classify(const dp_refs &dps);
  virtual void       train(const std::vector<Example> &examples) = 0;
  void               train(const DataSet &ds);
  void               train(const dp_refs &dps);
  virtual std::string getSpecification() = 0;
protected:
  features::IVisualFeatureFetcher::ptr fetcher;
};

class BasicClassifier : public Classifier{
private:
  ClassifierAlgorithm::ptr algorithm;
public:
                 BasicClassifier(features::IVisualFeatureFetcher::ptr f, 
				ClassifierAlgorithm::ptr algorithm);
  virtual Label classify( Descriptor::const_ptr desc);
  virtual void train(const std::vector<Example> &examples);
  virtual std::string getSpecification();
};

}}

#endif
