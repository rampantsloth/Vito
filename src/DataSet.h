#ifndef DATASET_H
#define DATASET_H

#include "FileSystem.h"
#include <string>
#include "boost/shared_ptr.hpp"
#include "Category.h"
#include "DataInfo.h"



namespace vito{

class Category;
class CategoryInfo;

class DataSet : public DataSetInfo{
private:
  FileSystem::ptr filesystem;
  std::vector<Category> categories;
public:
  DataSet(std::string rt, FileSystem::ptr fs);
  void print();
};


}

#endif
