#include "VitoApplication.h"

#include "BoostFileSystem.h"

using std::map;
using std::string;

namespace vito{

VitoApplication::VitoApplication() : filesystem(new BoostFileSystem()){
}

DataSet::ptr VitoApplication::loadDataset(std::string str){
  DataSet::ptr dataset( new DataSet(str, filesystem));
  datasets[dataset->getDataSetName()] = dataset;
  return dataset;
}

VitoApplication::~VitoApplication(){}

void  VitoApplication::setCategoryActivity(string ds, string cat, bool state){
  if(datasets.count(ds) > 0)
    datasets[ds]->setCategoryActivity(cat, state);
}

std::vector<const DataPoint * > VitoApplication::getActivePoints(){
  std::vector<const DataPoint *> result;
  for(map<string, DataSet::ptr>::iterator i = datasets.begin(); 
      i != datasets.end(); ++i){
    std::vector<const DataPoint *> dset_result = i->second->getActivePoints();
    result.insert(result.end(), dset_result.begin(), dset_result.end());
  }
  return result;
}


} // vito
