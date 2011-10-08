#ifndef BOOSTFILESYSTEM_H
#define BOOSTFILESYSTEM_H
#include "FileSystem.h"

namespace vito{

class BoostFileSystem : public FileSystem{
public:
  virtual             ~BoostFileSystem();
  virtual file_list    getFilesOfType(std::string type,
				   std::string directory) const;
  virtual size_t       getHash(std::string str) const;
  virtual void         createDir(std::string str);
  virtual bool         exists(std::string str);
};

}

#endif
