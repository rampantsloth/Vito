#include "DataInfo.h"

#include <iostream>
using std::string;
using std::cout;
using std::endl;

namespace vito{

// datapoint

DataPoint::DataPoint(string url_, FileSystem::ptr filesystem) :
  url(url_), filename(filesystem->getFileName(url_)){}

string DataPoint::getFileName() const{return filename;}
string DataPoint::getURL() const{ return url;}
string DataPoint::getIdentifier() const { 
  return "" + getDataSet() + "_" + getCategory() + "_" + getFileName(); 
}
// category

CategoryInfo::CategoryInfo(string root_, string name_, size_t label_) :
  root(root_), name(name_), label(label_){}

std::string CategoryInfo::getRoot() const{  return root; }
std::string CategoryInfo::getName() const{ return name; }
size_t CategoryInfo::getLabel() const{ return label; }

// dataset

DataSetInfo::DataSetInfo(std::string rt, std::string dsname) 
  : root(rt), dataset_name(dsname) {}

std::string DataSetInfo::getRoot() const { return root; }
std::string DataSetInfo::getDataSetName() const { return dataset_name; }
void        DataPoint::print(){
  std::cout << "\tDataPoint: " << std::endl;
  std::cout << "\t\t name: " << getFileName() << std::endl;
  std::cout << "\t\t url: " << getURL() << std::endl;
}
}
