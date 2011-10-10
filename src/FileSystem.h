#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <vector>
#include <string>
#include "boost/shared_ptr.hpp"

namespace vito{

class FileSystem{
public:
  typedef boost::shared_ptr<FileSystem> ptr;
  typedef std::vector<std::string> file_list;
protected:
  file_list valid_extensions;
public:
  // implemented stuff
  FileSystem();

  std::vector<float> &writeDescriptor(std::vector<float> &datapoints, 
				     std::string destination);
  std::vector<float> readDescriptor(std::string location);

  // pure stuff
  virtual bool        exists(std::string fileloc) const = 0;
  virtual bool        isImage(std::string im) const = 0;
  virtual bool        dirHasImages(std::string fileloc) const = 0;

  virtual void        createDir(std::string str) const = 0;

  virtual std::string getFileName(std::string) const = 0;
  virtual size_t      getHash(std::string str) const = 0;
  virtual file_list   getSubDirectories(std::string str) const = 0;
  virtual file_list   getFilesOfType(std::string type, 
				   std::string directory) const = 0;
  virtual file_list   getImageFiles(std::string root) const = 0;

  virtual            ~FileSystem(){}
};



}

#endif
