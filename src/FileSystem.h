#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>

namespace vito{

class FileSystem{
  typedef vector<std::string> file_list;
public:
  file_list getFilesOfType(std::string type, std::string directory) const = 0;
};

}

#endif
