#include "DataSet.h"

#include <iostream>

using std::map;
using std::cout;
using std::endl;
using std::vector;
using std::string;

namespace vito{

DataSet::DataSet() : DataSetInfo("empty" , "empty"), loaded(false) {}

DataSet::DataSet(string rt, FileSystem::ptr fs) : 
  DataSetInfo(rt, fs->getFileName(rt)), loaded(true){
  vector<string> cat_dirs = fs->getSubDirectories(rt);
  size_t label = 0;
  for(vector<string>::iterator i = cat_dirs.begin(); i != cat_dirs.end(); ++i){
    if( fs->dirHasImages(*i) ){
      Category cat (*i, label, fs, this);
      categories.insert(categories.end(), 
			map<string, Category>::value_type(cat.getName(),
							  cat));
      label++;
    }
  }
}

bool DataSet::isLoaded(){
  return loaded;
}

void DataSet::print(){
  cout << "Database:\n name: " <<  dataset_name << ":" << endl;
  cout << "at: " << root << endl;
  cout << "with categories: " << endl;
  for(std::map<string, Category>::iterator i = categories.begin(); 
      i != categories.end(); ++i)
    i->second.print();
}

const std::map<string, Category> *DataSet::getCategories(){
  return &categories;
}

void DataSet::setCategoryActivity(std::string cat, bool state){
  map<string, Category>::iterator s = categories.find(cat);
  if(s != categories.end())
    s->second.setActivity(state);
}

Category::dp_refs DataSet::getActivePoints(){
  dp_refs actives;
  for(catmap::iterator i = categories.begin(); i != categories.end(); ++i)
    if(i->second.getActivity()){
      dp_refs catrefs = i->second.getPoints();
      actives.insert(actives.end(), catrefs.begin(), catrefs.end());
  }
  return actives;
}

}
