#include "DataPoint.h"

using std::string;

namespace vito{


DataSetEntry::DataSetEntry(string url_, FileSystem::ptr fs,
			   const DataSetInfo *dset, const CategoryInfo *cat) :
  DataPoint(url_, fs), dataset(dset), category(cat) {

}
size_t      DataSetEntry::getLabel() const{ return category->getLabel();}
std::string DataSetEntry::getCategory() const{ return category->getName();}
std::string DataSetEntry::getDataSet() const { return dataset->getDataSetName();}


SingleDataPoint::SingleDataPoint(string location, FileSystem::ptr fs) :
  DataPoint(location, fs), label(999), cat("anonymous_category"), 
  dset("anonymous_dataset"){
    }
std::size_t SingleDataPoint::getLabel() const{ return label;}
std::string SingleDataPoint::getCategory() const{ return cat;}
std::string SingleDataPoint::getDataSet() const{ return dset;}



} // vito
