#ifndef CACHED_FEATURE_EXTRACTOR_H
#define CACHED_FEATURE_EXTRACTOR_H

#include "IVisualFeatureFetcher.h"
#include "IVisualFeatureExtractor.h"
#include "LRUCache.h"


namespace vito{
namespace features{

class CachedFeatureFetcher : public IVisualFeatureFetcher{
  IVisualFeatureExtractor::ptr extractor;
  LRUCache<Descriptor> cache;
public:
  CachedFeatureFetcher(IVisualFeatureExtractor::ptr ext):
    extractor(ext), cache(1000){
  }
  virtual Descriptor::const_ptr extract(const DataPoint *dp, 
					RgbImage *visrep = 0);

  virtual std::string getSpecification();
};

} // features
} // vito

#endif
