#include "Category.h"

using std::vector;
using std::string;

namespace vito{

Category::Category(string rt, size_t lbl,
		   FileSystem::ptr fs,
		   const DataSetInfo *info) :
  CategoryInfo(rt, fs->getFileName(rt), lbl), 
  filesystem(fs), 
  parent(info){
  vector<string> files = filesystem->getImageFiles(getRoot());
  for(vector<string>::iterator i = files.begin(); i != files.end(); ++i)
    entries.push_back( DataSetEntry(*i, fs, parent, this ) );
}


}
