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
Extractor::ptr FeatureFactory::getExtractor(string str,
					    ParameterDataSource::ptr dsrc,
					    bool normalized, bool stored){
  dsrc->add(str, "normalized", normalized);
  dsrc->add(str, "stored", stored);
  return getExtractor(str, dsrc);
}

Extractor::ptr FeatureFactory::getExtractor(string str, 
					    ParameterDataSource::ptr dsource)  {
  bool stored = dsource->get(str, "stored", true);
  if(stored)
    dsource = ParameterDataSource::ptr(new ParameterDataSourceRecorder(dsource));

  bool normalized = dsource->get(str, "normalized", true);
  IVisualFeatureExtractor::ptr ext(new VisualFeatureExtractor
				   (getAlgorithm(str, dsource)));
  if(normalized)
    ext = IVisualFeatureExtractor::ptr( new NormalizedFeatureExtractor(ext) );
  if(stored) 
    ext = IVisualFeatureExtractor::ptr( new StoredFeatureExtractor(ext, filesystem,
								   DESCRIPTORLOCATION, 
								   dsource->getSpecification() ) );
  return ext;
}

Fetcher::ptr FeatureFactory::getFetcher(string tr, bool stored, bool norm){

}


} // features
} // vito
