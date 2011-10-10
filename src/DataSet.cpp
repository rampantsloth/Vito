#include "DataSet.h"

#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

namespace vito{



DataSet::DataSet(string rt, FileSystem::ptr fs) : 
  DataSetInfo(rt, fs->getFileName(rt)){
  vector<string> cat_dirs = fs->getSubDirectories(rt);
  size_t label = 0;
  for(vector<string>::iterator i = cat_dirs.begin(); i != cat_dirs.end(); ++i){
    if( fs->dirHasImages(*i) ){
      categories.push_back( Category(*i, label, fs, this) );
      label++;
    }
  }
}

void DataSet::print(){
  cout << "Database:\n name: " <<  dataset_name << ":" << endl;
  cout << "at: " << root << endl;
  cout << "with categories: " << endl;
  for(vector<Category>::iterator i = categories.begin(); 
      i != categories.end(); ++i)
    i->print();
}

}
