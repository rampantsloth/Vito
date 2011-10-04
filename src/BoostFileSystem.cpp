#include "BoostFileSystem.h"
#include "boost/filesystem.hpp"
#include <iostream>

typedef vito::FileSystem::file_list file_list;

namespace vito{

using std::cout;
using std::endl;
using std::string;
using boost::filesystem::path;
using boost::filesystem::extension;
typedef boost::filesystem::directory_iterator dir_it;

BoostFileSystem::~BoostFileSystem(){
}

file_list BoostFileSystem::getFilesOfType(string type, string dir) const{
  file_list list;  
path root(dir);
 for(dir_it i(root); i != dir_it(); ++i)
   if(extension(*i) == ".dylib")
     list.push_back(i->string());
  return list;
}

}
