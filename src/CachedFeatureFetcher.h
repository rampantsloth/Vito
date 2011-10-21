#ifndef CACHED_FEATURE_EXTRACTOR_H
#define CACHED_FEATURE_EXTRACTOR_H

#include "IVisualFeatureFetcher.h"
#include "IVisualFeatureExtractor.h"
#include "LRUCache.h"


namespace vito{
namespace features{

class CachedFeatureFetcher : public IVisualFeatureFetcher{
  IVisualFeatureExtractor::ptr extractor;
  LRUCache<Descriptor::ptr> cache;
public:
  CachedFeatureFetcher(IVisualFeatureExtractor::ptr ext):
    extractor(ext), cache(100){
  }
  virtual const Descriptor * extract(const DataPoint *dp, 
					RgbImage *visrep = 0);
};

} // features
} // vito

#endif
