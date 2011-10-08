#include "ParameterDataSourceRecorder.h"

using std::string;
#include <iostream>

namespace vito{

std::string ParameterDataSourceRecorder::getSpecification(){
  return record->getSpecification();
}

size_t ParameterDataSourceRecorder::get(string str, string parent, size_t original) {
  size_t val = true_source->get(str, parent, original);
  record->add(str, parent, val);
  return val;
}
int ParameterDataSourceRecorder::get(string str, string parent, int original) {
  int val = true_source->get(str, parent, original);
  record->add(str, parent, val);
  return val;
}
double ParameterDataSourceRecorder::get(string str, string parent, double original) {
  double val = true_source->get(str, parent, original);
  record->add(str, parent, val);
  return val;
}
bool ParameterDataSourceRecorder::get(string str, string parent, bool original) {
  bool val = true_source->get(str, parent, original);
  record->add(str, parent, val);
  return val;
}

void ParameterDataSourceRecorder::add(string str, string parent, size_t value) {
  true_source->add(str, parent, value);
}
void ParameterDataSourceRecorder::add(string str, string parent, int value) {
  true_source->add(str, parent, value);
}
void ParameterDataSourceRecorder::add(string str, string parent, double value) {
  true_source->add(str, parent, value);
}
void ParameterDataSourceRecorder::add(string str, string parent, bool value) {
  true_source->add(str, parent, value);
}


}
