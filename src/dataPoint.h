#ifndef DATAPOINT_H
#define DATAPOINT_H

#include "DataInfo.h"
#include "DataSet.h"


namespace vito{

 class Category;

class DataSetEntry : public DataPoint{
  friend class Category;
private:
  const DataSetInfo *dataset;
  const CategoryInfo *category;
protected:
  DataSetEntry(std::string url, FileSystem::ptr fs, 
	       const DataSetInfo *dataset, const CategoryInfo *category);
  virtual std::size_t getLabel() const;
  virtual std::string getCategory() const;
  virtual std::string getDataSet() const;
};

class SingleDataPoint : public DataPoint{
private:
  size_t label;
  std::string cat;
  std::string dset;
public:
  SingleDataPoint(std::string location, FileSystem::ptr fs);
  virtual std::size_t getLabel() const;
  virtual std::string getCategory() const;
  virtual std::string getDataSet() const;
};

}

#endif
