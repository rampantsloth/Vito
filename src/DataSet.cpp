#include "DataSet.h"
#include <iostream>
#include "Exceptions.h"

#include <sstream>

using std::map;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::random_shuffle;
namespace vito{

DataSet::DataSet() : DataSetInfo("empty" , "empty"), loaded(false) {}

DataSet::DataSet(string rt, FileSystem::ptr fs) : 
  DataSetInfo(rt, fs->getFileName(rt)), loaded(true){
  vector<string> cat_dirs = fs->getSubDirectories(rt);
  size_t label = 0; 
  for(vector<string>::iterator i = cat_dirs.begin(); i != cat_dirs.end(); ++i){
    if( fs->dirHasImages(*i) ){
      Category::ptr cat( new Category(*i, label, fs, this));
      categories.insert(categories.end(), 
			catmap::value_type(cat->getName(),
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
  for(catmap::iterator i = categories.begin(); i != categories.end(); ++i)
    i->second->print();
}

const std::map<string, Category::ptr> *DataSet::getCategories(){
  return &categories;
}

void DataSet::setCategoryActivity(std::string cat, bool state){
  catmap::iterator s = categories.find(cat);
  if(s != categories.end())
    s->second->setActivity(state);
  else
    throw exception::CategoryNotFound();
}

void DataSet::activate(std::string str){
  setCategoryActivity(str, true);
}

Category::dp_refs DataSet::getActivePoints() const{
  dp_refs actives;
  for(catmap::const_iterator i = categories.begin(); i != categories.end(); ++i)
    if(i->second->getActivity()){
      dp_refs catrefs = i->second->getPoints();
      actives.insert(actives.end(), catrefs.begin(), catrefs.end());
  }
  return actives;
}

size_t DataSet::smallestActiveCategory() const{
  int smallest_size = -1;
  for(catmap::const_iterator i = categories.begin(); i != categories.end(); ++i)
    if(i->second->getActivity() && ( (int) i->second->size() < smallest_size || smallest_size == -1))
      smallest_size = i->second->size();
  if(smallest_size == -1 ) smallest_size = 0;
  return smallest_size;
}

DataSet::Split DataSet::split(double ratio, bool eq_rep) const {
  if(ratio < 0 || ratio > 1) ratio = 0.5;
  size_t smallest_size = smallestActiveCategory();
  return split(smallest_size * ratio, smallest_size * (1.0 - ratio), eq_rep);
}

DataSet::Split DataSet::split(size_t train, size_t test,
			      bool eq_rep ) const {
  size_t total = train + test;
  size_t smallest_size = smallestActiveCategory();
  if(total > smallest_size && eq_rep){
    double ratio = (double) train / (double) total;
    total = smallest_size;
    train = total * ratio;
  }
  Split split;
  for(catmap::const_iterator i = categories.begin(); i != categories.end(); ++i){
    if(i->second->getActivity()){
      if(!eq_rep){
	double ratio = (double) train / (double) i->second->size();
	total = smallest_size;
	train = total * ratio;
      }
      dp_refs all =  i->second->getPoints();
      random_shuffle(all.begin(), all.end());
      size_t num_j = 0;
      for(dp_refs::const_iterator j = all.begin(); 
	  j != all.end() && num_j < total; ++j){
	if(num_j < train){
	  split.train.push_back(*j);
	}else{
	  split.test.push_back(*j);
	}
	num_j++;
      } 
    } // activity > 0
  } // for loop
  return split;
}

std::string DataSet::getSpecification() const{
  std::stringstream ss;
  vector<string> active_cats = getActiveCategories();
  ss << getDataSetName() << "_with_cats:{_";
  for(vector<string>::iterator i = active_cats.begin();
      i != active_cats.end(); ++i)
    ss << *i << "_";
  ss << "}";
  return ss.str();
}

vector<string> DataSet::getActiveCategories() const{
  vector<string> active_cats;
  for(catmap::const_iterator i = categories.begin(); i != categories.end(); ++i)
    if(i->second->getActivity())
      active_cats.push_back(i->second->getName());
  return active_cats;
}  


}
