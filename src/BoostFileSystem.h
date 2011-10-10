#ifndef BOOSTFILESYSTEM_H
#define BOOSTFILESYSTEM_H
#include "FileSystem.h"

namespace vito{

class BoostFileSystem : public FileSystem{
public:
  virtual bool        exists(std::string fileloc) const; //
  virtual bool        dirHasImages(std::string fileloc) const; //
  virtual bool        isImage(std::string im) const; //
  virtual void        createDir(std::string str) const; //

  virtual std::string getFileName(std::string) const; //
  virtual size_t      getHash(std::string str) const; //
  virtual file_list   getSubDirectories(std::string str) const; 
  virtual file_list   getFilesOfType(std::string type, 
				     std::string directory) const; //
  virtual file_list   getImageFiles(std::string root) const; //

  virtual             ~BoostFileSystem(); //
};

}

#endif
