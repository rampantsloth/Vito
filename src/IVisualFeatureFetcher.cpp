#include "IVisualFeatureFetcher.h"


namespace vito{
namespace features{

Example IVisualFeatureFetcher::extractExample (const DataPoint *dp,
					       RgbImage *visrep){
  Example ex(extract(dp), dp->getLabel());
  return ex;
}

vector<Example> IVisualFeatureFetcher::extractExamples(const dp_refs &dps){
  vector<Example> examples;
  examples.reserve(dps.size());
  for(dp_refs::const_iterator i = dps.begin(); i != dps.end(); ++i){
    Example ex = extractExample(*i);
    examples.push_back( ex );
  }
  return examples;
}

} // features
} // vito

