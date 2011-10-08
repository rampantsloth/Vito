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

  // implemented stuff
  std::vector<float> &writeDescriptor(std::vector<float> &datapoints, 
				     std::string destination);
  std::vector<float> readDescriptor(std::string location);

  // pure stuff
  virtual bool       exists(std::string fileloc) = 0;
  virtual void       createDir(std::string str) = 0;
  virtual size_t     getHash(std::string str) const = 0;
  virtual file_list  getFilesOfType(std::string type, 
				   std::string directory) const = 0;
  virtual           ~FileSystem(){}
};



}

#endif
