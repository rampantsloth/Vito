#ifndef VITOAPPLICATION_H
#define VITOAPPLICATION_H

#include <map>
#include "DataSet.h"

namespace vito{

class VitoApplication{
protected:
  std::map<std::string, DataSet::ptr> datasets;
  FileSystem::ptr filesystem;
public:
  VitoApplication();
  DataSet::ptr loadDataset(std::string str);
  void         setCategoryActivity(std::string ds, std::string cat, bool state);

  virtual     ~VitoApplication();
  std::vector<const DataPoint * > getActivePoints();
};

}

#endif
