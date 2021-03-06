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
  parent(info),
  activity(false) {
  vector<string> files = filesystem->getImageFiles(getRoot());
  for(vector<string>::iterator i = files.begin(); i != files.end(); ++i){
    DataSetEntry entry(*i, fs, parent, this );
    entries.push_back( entry );
  }
}

void Category::print(){
  cout << " Category: " << endl;
  cout << "\t Name: " << name << endl;
  cout << "\t at: " << root << endl;
  for(vector<DataSetEntry>::iterator i = entries.begin();
      i != entries.end(); ++i)
    i->print();
}

void Category::setActivity(bool state){
  activity = state;
}

bool Category::getActivity() const {
  return activity;
}

Category::dp_refs Category::getPoints() const {
  dp_refs result;
  result.reserve(entries.size());
  for(std::vector<DataSetEntry>::const_iterator i = entries.begin(); 
      i != entries.end(); ++i){
    result.push_back(&*i);
  }
  return result;
}

size_t Category::size() const{
  return entries.size();
}

} // vito
