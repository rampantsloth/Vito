#ifndef DATASET_H
#define DATASET_H

#include "FileSystem.h"
#include "Category.h"
#include "DataInfo.h"
#include <string>
#include <map>

namespace vito{

class Category;
class CategoryInfo;

class DataSet : public DataSetInfo{
public:
  typedef std::map<std::string, Category> catmap;
  typedef boost::shared_ptr<DataSet> ptr;
  typedef std::vector< const DataPoint * > dp_refs;
private:
  bool loaded;
  FileSystem::ptr filesystem;
  catmap categories;
public:
  DataSet(std::string rt, FileSystem::ptr fs);
  DataSet();

  bool          isLoaded();
  void          print();
  const catmap *getCategories();
  void          setCategoryActivity(std::string cat,
				    bool state);
  dp_refs       getActivePoints();
};


}

#endif
