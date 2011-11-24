#ifndef STATISTICS_H
#define STATISTICS_H

#include <map>
#include <set>
#include "DataInfo.h"
#include "Labels.h"
#include "Matrix.h"

namespace vito{

class Statistics{
  typedef std::vector< const DataPoint * > dp_refs;
  typedef std::string string;
  typedef std::map< int, std::map < int, int> > ConfusionMatrix;

  ConfusionMatrix       confusion_matrix;
  LabelCollection classification;
  LabelCollection target;

  std::map<size_t, string> class_names;
  size_t correct, incorrect, total;
  std::set<int> available_labels;
public:
  Statistics();
  void   addRepetition(dp_refs test, LabelCollection labels);
  void   report();
  double getPrecision();
};

}

#endif
