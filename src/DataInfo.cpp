#include "DataInfo.h"

using std::string;

namespace vito{

// datapoint

DataPoint::DataPoint(string url_, FileSystem::ptr filesystem) :
  url(url_), filename(filesystem->getFileName(url_)){}

string DataPoint::getFileName() const{return filename;}
string DataPoint::getURL() const{ return url;}
string DataPoint::getIdentifier() const { 
  return getDataSet() + "_" + getCategory() + "_" + getFileName(); 
}
// category

CategoryInfo::CategoryInfo(string root_, string name_, size_t label_) :
  root(root_), name(name_), label(label_){}

std::string CategoryInfo::getRoot() const{  return root; }
std::string CategoryInfo::getName() const{ return getName(); }
size_t CategoryInfo::getLabel() const{ return label; }

// dataset

DataSetInfo::DataSetInfo(std::string rt, std::string dsname) 
  : root(rt), dataset_name(dsname) {}

std::string DataSetInfo::getRoot() const { return root; }
std::string DataSetInfo::getDataSetName() const { return dataset_name; }

}
