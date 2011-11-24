#include "Statistics.h"

using std::cout;
using std::endl;

namespace vito{

Statistics::Statistics() : correct(0), incorrect(0), total(0) {}

void Statistics::addRepetition(dp_refs test, LabelCollection labels){
  // iterate datapoints and labels
  dp_refs::iterator dpit = test.begin();
  LabelCollection::iterator labit = labels.begin();
  while(dpit != test.end() && labit != labels.end()){
    // save catname to label
    if( !class_names.count( (*dpit)->getLabel() ) )
      class_names[(*dpit)->getLabel()] = (*dpit)->getCategory(); 
    // add label to set
    available_labels.insert((*dpit)->getLabel());
    // add to confusion matrix
    confusion_matrix[(*dpit)->getLabel()][*labit] += 1;
    // add statistics
    if((int) (*dpit)->getLabel() ==  *labit)
      correct++;
    else
      incorrect++;
    total++;
    ++dpit, ++labit;
  }
}

double Statistics::getPrecision(){
  return (double) correct / (double) total;
}

void Statistics::report(){
  cout << endl << "precision: " << correct << "/" << total 
       << " = " << getPrecision() << "%" << endl << endl;
  cout << "Confusion Matrix: " << endl;
  printf("%8s   ", "label:");
  for(std::set<int>::iterator i = available_labels.begin();
      i != available_labels.end(); ++i)
    printf("%7d: ", *i);    
  cout << endl << endl;
  for(std::set<int>::iterator i = available_labels.begin(); 
      i!= available_labels.end(); ++i){
    printf("%7d   :", *i);
    for(std::set<int>::iterator j = available_labels.begin(); 
	j!= available_labels.end(); ++j){
      printf("%7d  ", confusion_matrix[*i][*j]);
    }
    cout << endl;
  }
  cout << endl;
}

}
