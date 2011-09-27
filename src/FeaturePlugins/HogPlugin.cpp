#include "FeatureAlgorithmPlugin.h"
#include "HoG.cpp"
#include "ParameterDataSource.h"

using vito::features::VisualFeatureAlgorithm;
using vito::features::HoG;
using vito::features::HoGParameters;
using vito::ParameterDataSource;


extern "C"{

  SP<VisualFeatureAlgorithm> makeFeature(vito::ParameterDataSource *source){
    #define set(dummy) parameters.dummy = source->get(#dummy, parameters.dummy);
    HoGParameters parameters;
    set(blur);
    set(blur_size);
    set(xhistograms);
    set(yhistograms);
    set(orientations);
    SP<VisualFeatureAlgorithm> algorithm(new HoG(parameters));
    return algorithm;
  };

  class Initializer{
  public:
    Initializer(){
      feature_factory["HoG"] = makeFeature;
  }
  };
  Initializer p;
}
