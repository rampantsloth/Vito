#include "Category.h"

#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

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

void Category::print(){
  cout << " Category: " << endl;
  cout << "\t Name: " << name << endl;
  cout << "\t at: " << root << endl;
  for(vector<DataSetEntry>::iterator i = entries.begin();
      i != entries.end(); ++i)
    i->print();
}


}
