#include "NormalizedFeatureExtractor.h"

namespace vito{
namespace features{

Descriptor NormalizedFeatureExtractor::extract(DataPoint dp, 
					       RgbImage *visrep){
  return extractor->extract(dp,visrep);
}

} // features
} // vito
