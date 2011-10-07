#include "StoredFeatureExtractor.h"

namespace vito{
namespace features{

Descriptor StoredFeatureExtractor::extract(DataPoint dp, 
					       RgbImage *visrep){
  return extractor->extract(dp,visrep);
}

} // features
} // vito
