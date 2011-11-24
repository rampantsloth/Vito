#ifndef CATEGORY_H
#define CATEGORY_H

#include <vector>
#include "DataInfo.h"
#include "DataPoint.h"
//#include "DataSet.h"

namespace vito{

class DataSet;
class DataSetEntry;

class Category : public CategoryInfo{
public:
  typedef boost::shared_ptr<Category> ptr;
  typedef boost::shared_ptr<const Category> const_ptr;
  typedef std::vector< const DataPoint * > dp_refs;
friend class DataSet;
  FileSystem::ptr filesystem;
  const DataSetInfo *parent;
  std::vector<DataSetEntry> entries;
  bool activity;
protected:
  Category( std::string root, size_t label, 
	    FileSystem::ptr fs, const DataSetInfo *info );
public:
  void setActivity(bool state);
  bool getActivity() const ;
  void print();
  dp_refs getPoints() const;
  size_t size() const;

};

}

#endif
