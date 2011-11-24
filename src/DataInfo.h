#ifndef DATAINFO_H
#define DATAINFO_H

#include <string>
#include "FileSystem.h"

namespace vito{

class DataSetInfo{
protected:
  std::string root;
  std::string dataset_name;
protected:
  DataSetInfo(std::string root, std::string dataset_name);
public:
  std::string getRoot() const;
  std::string getDataSetName() const;
};

class CategoryInfo{
protected:
  std::string root;
  std::string name;
  size_t label;
  CategoryInfo( std::string root, std::string name, size_t label);
public:
  virtual std::string getRoot() const;
  virtual std::string getName() const;
  virtual size_t      getLabel() const;
};

class DataPoint{
protected:
  std::string url;
  std::string filename;
public:
  DataPoint(std::string url, FileSystem::ptr fs);
          std::string getFileName() const;
          std::string getURL() const;
          std::string getIdentifier() const;
  virtual std::size_t getLabel() const = 0 ;
  virtual std::string getCategory() const = 0;
  virtual std::string getDataSet() const = 0;
  void print();
  virtual ~DataPoint(){}
};

}

#endif
