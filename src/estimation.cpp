#include "estimation.h"

namespace vito{
namespace classification{


Estimation::Estimation(const int i) : result(i), likeliness(1.0), duality(0.0){
  probability[i] = 1.0;
}

Estimation::Estimation(const Probabilities  &probs) : duality(0){
  float max = 0;
  for(Probabilities::const_iterator i = probs.begin(); i != probs.end(); ++i){
    if(i->second > max){
      max = i->second;
      result = i->first;
    }
    duality += i->second;
    probability[i->first] = i->second;
  }
  likeliness = max;
  duality -= likeliness;
}


}}
