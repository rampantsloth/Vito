#include "FeatureAlgorithmPlugin.h"
#include "HoG.cpp"
#include "ParameterDataSource.h"
#include <iostream>


using vito::features::VisualFeatureAlgorithm;
using vito::features::HoG;
using vito::ParameterDataSource;

extern "C"{


  VisualFeatureAlgorithm::ptr makeHoG(vito::ParameterDataSource::ptr source){
#define set(dummy, std) parameters.dummy = source->get("HoG", #dummy, std);
    HoG::Parameters parameters;
    set(blur, true);
    set(blur_size, 5);
    set(xhistograms, 4);
    set(yhistograms, 4);
    set(orientations, 8);
    VisualFeatureAlgorithm::ptr algorithm(new HoG(parameters));
    return algorithm;
  };

  class HOGInitializer{
  public:
    HOGInitializer(){
      std::cout << "adding HoG" << std::endl;
      feature_factory["HoG"] = makeHoG;
  }
  };
  HOGInitializer p;
}
