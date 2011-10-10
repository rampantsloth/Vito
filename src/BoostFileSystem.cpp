#include "BoostFileSystem.h"
#include "boost/filesystem.hpp"
#include <iostream>
#include "boost/functional/hash.hpp"

typedef vito::FileSystem::file_list file_list;

namespace vito{

using std::cout;
using std::endl;
using std::string;
using boost::filesystem::path;
using boost::filesystem::extension;
using boost::filesystem::is_directory;
typedef boost::filesystem::directory_iterator dir_it;

BoostFileSystem::~BoostFileSystem(){
}

file_list BoostFileSystem::getSubDirectories(std::string str) const{
  file_list subdirs;
  path root(str);
  for(dir_it i(root); i != dir_it(); ++i)
    if(is_directory(*i))
      subdirs.push_back(i->string());
  return subdirs;
}

bool BoostFileSystem::isImage(std::string im) const{
  path p(im);
  for(file_list::const_iterator i = valid_extensions.begin(); 
      i != valid_extensions.end(); ++i){
    if(extension(p) == *i)
      return true;
  }
  return false;
}

bool BoostFileSystem::dirHasImages(std::string dir) const {
  path root(dir);
  for(dir_it i(root); i != dir_it(); ++i)
    if(isImage(i->string()))
      return true;
 return false;
}

string BoostFileSystem::getFileName(string url) const {
  path p(url);
  return p.filename();
}

file_list BoostFileSystem::getImageFiles(string dir) const {
  file_list total;
  path root(dir);
  for(dir_it i(root); i != dir_it(); ++i)
    if(isImage(i->string()))
      total.push_back(i->string());
  return total;
}

file_list BoostFileSystem::getFilesOfType(string type, string dir) const{
  file_list list;  
  path root(dir);
 for(dir_it i(root); i != dir_it(); ++i)
   if(extension(*i) == ".dylib")
     list.push_back(i->string());
  return list;
}

size_t  BoostFileSystem::getHash(std::string str) const{
  boost::hash<std::string> hasher;
  return hasher(str);
}

void BoostFileSystem::createDir(std::string str) const {
  cout << "creating " << str << endl;
  path dir(str);
  if(!boost::filesystem::exists(str) || !is_directory(dir)) create_directory(dir);
}

bool BoostFileSystem::exists(std::string str) const {
  return boost::filesystem::exists(path(str));
}

}
