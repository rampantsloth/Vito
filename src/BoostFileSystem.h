#ifndef BOOSTFILESYSTEM_H
#define BOOSTFILESYSTEM_H
#include "FileSystem.h"
#include "FeatureFactory.h"

namespace vito{

class BoostFileSystem : public FileSystem{
public:
  virtual ~BoostFileSystem();
  virtual file_list getFilesOfType(std::string type,
				   std::string directory) const;
};

}

#endif
