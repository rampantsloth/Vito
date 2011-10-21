#include "Classifier.h"

namespace vito{
namespace classification{

using features::IVisualFeatureFetcher;

Classifier::Classifier(IVisualFeatureFetcher::ptr f): fetcher(f){
}

Classifier::~Classifier(){
}

Label Classifier::classify(const DataPoint *dp){
  return classify(fetcher->extract(dp));
}


BasicClassifier::BasicClassifier(IVisualFeatureFetcher::ptr f, 
				 ClassifierAlgorithm::ptr alg) :
  Classifier(f), algorithm(alg){
}

Label   BasicClassifier::classify(const Descriptor * desc){
  return algorithm->classify(*desc);
}

} // classification
} // vito
