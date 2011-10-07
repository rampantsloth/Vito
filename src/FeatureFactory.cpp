#include "FeatureFactory.h"
#include "NormalizedFeatureExtractor.h"
#include "StoredFeatureExtractor.h"

using std::cout;
using std::endl;
using std::string;

typedef vito::features::FeatureFactory::factory factory;
factory feature_factory;

namespace vito{
namespace features{

typedef IVisualFeatureFetcher Fetcher;
typedef IVisualFeatureExtractor Extractor;


const factory& FeatureFactory::getFactory() const{
  return feature_factory;
}

Extractor::ptr FeatureFactory::getExtractor(string str, bool stored, 
					    bool normalized)  {
  IVisualFeatureExtractor::ptr ext(new VisualFeatureExtractor 
					 (getAlgorithm(str)));
  if(normalized)
    ext = IVisualFeatureExtractor::ptr( new NormalizedFeatureExtractor(ext) );
  if(stored) 
    ext = IVisualFeatureExtractor::ptr( new StoredFeatureExtractor(ext) );
  return ext;
}

Fetcher::ptr FeatureFactory::getFetcher(string tr, bool stored, bool norm){

}


} // features
} // vito
