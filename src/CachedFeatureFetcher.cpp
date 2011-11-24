#include "CachedFeatureFetcher.h"

#include "Exceptions.h"
#include <iostream>

namespace vito{
namespace features{

using std::cout;
using std::endl;

using std::string;

std::string CachedFeatureFetcher::getSpecification(){
  return extractor->getSpecification();
}

Descriptor::const_ptr CachedFeatureFetcher::extract(const DataPoint *dp, 
						    RgbImage *visrep){
  string id = dp->getIdentifier();
  Descriptor::ptr descriptor = cache.find(id);
  if(descriptor == 0){
    Descriptor::ptr desc(new Descriptor());
    *desc = extractor->extract(dp, visrep);
    cache.insert(id, desc);
    descriptor = desc;
  }
  if(descriptor == 0)
    throw exception::CacheReadingError();
  return descriptor;
  }

} // vito
} // features
