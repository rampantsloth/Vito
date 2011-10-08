#include "StoredFeatureExtractor.h"

#include <stdlib.h>
#include <stdio.h>
#include<boost/lexical_cast.hpp>

namespace vito{
namespace features{

StoredFeatureExtractor::StoredFeatureExtractor(IVisualFeatureExtractor::ptr e, 
					       FileSystem::ptr fs, 
					       std::string storagelocation,
					       std::string hsh):
  VisualFeatureDecorator(e), filesystem(fs), 
  directory(storagelocation + boost::lexical_cast<string>(fs->getHash(hsh))){
  filesystem->createDir(directory);
}

Descriptor StoredFeatureExtractor::extract(DataPoint dp, 
					   RgbImage *visrep){
  cout << "stored feature here" << endl;
  std::string location = directory +  "/"  + dp.get_file_name();
  if(filesystem->exists(location))
    return Descriptor(filesystem->readDescriptor(location));
  else{
    vector<float> desc = extractor->extract(dp,visrep);
    return filesystem->writeDescriptor(desc, location);
  }
}

} // features
} // vito
