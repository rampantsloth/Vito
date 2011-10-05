#ifndef FEATUREALGORITHMPLUGIN_H
#define FEATUREALGORITHMPLUGIN_H

/* A plugin is always paramterized, even when they do not need any
   paramters to ensure they are loaded uniformly */
#include "FeatureFactory.h"

// In the program at flat namespace level, a map is kept of every
// FeatureMakerFunction to which each FeatureMaker function should be
// added

extern vito::features::FeatureFactory::factory feature_factory;

/* ----------------- Tutorial -------------------------
To create A Visual Feature Algorithm Plugin:
1. create a VisualFeatureAlgorithm by extending this class
2. Then create a <FEATURENAME>Plugin.cpp
3. Export your code using ' extern "C"{ }'
4. create a FeatureMaker function:
       SP<VisualFeatureAlgorithm> makeFeature(IParameterDataSource *source){...}
   in which you must retrieve and set the parameter data the
   VisualFeatureAlgorithm needs using the ParameterDataSource::get function.
5. Create A local Initializer class like this:

class Initializer{
  public:
    Initializer(){
      feature_maker["YOUR_FEATURE_NAME"] = makeFeature;
  }
  };

6. Initialize the Initialize with a global variable (this causes your 
featuremaker function to be registered at runtime):

   Initializer p;

7. You are done, while using the makefile, the plugin will be
automatically be compiled and included at runtime.

*/
#endif
