#ifndef STOREDFEATUREEXTRACTOR_H
#define STOREDFEATUREEXTRACTOR_H

#include "FileSystem.h"
#include "VisualFeatureDecorator.h"
#include "ParameterDataSourceRecorder.h"


namespace vito{
namespace features{

class StoredFeatureExtractor : public VisualFeatureDecorator{
private:
  FileSystem::ptr filesystem;
  std::string directory;
public:
  StoredFeatureExtractor(IVisualFeatureExtractor::ptr e, FileSystem::ptr fs, 
			 std::string storagelocation, std::string hsh) ;
  virtual Descriptor extract(DataPoint dp, RgbImage *visrep = 0);
  virtual std::string getName(){
    return "stored_" + extractor->getName();
  }
};

} // features
} // vito

#endif
