#ifndef CACHED_FEATURE_EXTRACTOR_H
#define CACHED_FEATURE_EXTRACTOR_H

#include "VisualFeatureExtractor.h"
#include "LRUCache.h"


namespace vito{
namespace features{

class CachedFeatureExtractor : public IVisualFeatureFetcher{
  SP<IVisualFeatureExtractor> extractor;
  LRUCache<Descriptor> cache;
public:
  CachedFeatureExtractor(SP<IVisualFeatureExtractor> ext):
    extractor(ext), cache(100){
  }
  virtual Descriptor extract(DataPoint dp, RgbImage *visrep = 0){
    std::string id = dp.get_identifier();
    LRUCache::CacheMap::iterator descriptor = cache.find(id);
    if(descriptor == map::end){
      SP<Descriptor> desc =  feature->extract(image, visrep);
      cache.include(id, desc);
      return desc;
    }
    return *descriptor;
  }
};

} // features
} // vito

#endif
