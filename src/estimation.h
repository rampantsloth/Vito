#ifndef ESTIMATION_H
#define ESTIMATION_H

#include <vector>
#include <map>

namespace vito{
namespace classification{

typedef std::pair<int, float> Probability;
typedef std::vector<Probability > Probabilities;

struct Estimation{
  Estimation(const int i);
  Estimation(const Probabilities &probs);
  int result;
  std::map<int, float> probability;
  float likeliness;
  float duality;
};

typedef std::vector<Estimation> EstimationCollection;

}}

#endif
