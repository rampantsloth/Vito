#include "FeatureAlgorithmPlugin.h"
#include "HoG.cpp"
#include "ParameterDataSource.h"
#include <iostream>


using vito::features::VisualFeatureAlgorithm;
using vito::features::HoG;
using vito::ParameterDataSource;

extern "C"{

  VisualFeatureAlgorithm::ptr makeHoG(vito::ParameterDataSource::const_ptr source){
    #define set(dummy) parameters.dummy = source->get("HoG", #dummy, parameters.dummy);
    HoG::Parameters parameters;
    set(blur);
    set(blur_size);
    set(xhistograms);
    set(yhistograms);
    set(orientations);
    VisualFeatureAlgorithm::ptr algorithm(new HoG(parameters));
    return algorithm;
  };

  class HOGInitializer{
  public:
    HOGInitializer(){
      std::cout << "hey im Hog" << std::endl;
      feature_factory["HoG"] = makeHoG;
  }
  };
  HOGInitializer p;
}
