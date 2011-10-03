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
  virtual file_list getFilesOfType(std::string type, 
				   std::string directory) const = 0;
};

}

#endif
