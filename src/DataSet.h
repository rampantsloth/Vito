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
  typedef std::map<std::string, Category::ptr > catmap;
  typedef boost::shared_ptr<DataSet> ptr;
  typedef std::vector< const DataPoint * > dp_refs;
  struct Split{
    dp_refs train;
    dp_refs test;
  };
private:
  bool loaded;
  FileSystem::ptr filesystem;
  catmap  categories;
public:
  DataSet(std::string rt, FileSystem::ptr fs);
  DataSet();

  bool          isLoaded();
  void          print();
  const catmap *getCategories();
  void          setCategoryActivity(std::string cat,
				    bool state);
  std::string   getSpecification() const;
  void          activate(std::string str);
  dp_refs       getActivePoints() const ;
  size_t        smallestActiveCategory() const ;
  Split         split(size_t train, size_t test, bool eq_rep = true ) const;
  Split         split(double ratio = 0.5, bool eq_rep = true) const ;
  std::vector<std::string> getActiveCategories() const;
};


}

#endif
