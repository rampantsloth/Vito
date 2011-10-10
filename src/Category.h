#ifndef CATEGORY_H
#define CATEGORY_H

#include <vector>
#include "DataInfo.h"
#include "DataPoint.h"
#include "DataSet.h"

namespace vito{

class DataSet;
class DataSetEntry;

class Category : CategoryInfo{
friend class DataSet;
  FileSystem::ptr filesystem;
  const DataSetInfo *parent;
  std::vector<DataSetEntry> entries;
protected:
  Category( std::string root, size_t label, 
	    FileSystem::ptr fs, const DataSetInfo *info );

};

}

#endif
