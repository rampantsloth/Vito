#ifndef CLASSIFIERPLUGIN_H
#define CLASSIFIERPLUGIN_H

#include "ClassifierFactory.h"

/* A plugin is always paramterized, even when they do not need any
   paramters to ensure they are loaded uniformly */

// In the program at flat namespace level, a map is kept of every
// FeatureMakerFunction to which each FeatureMaker function should be
// added

extern vito::classification::ClassifierFactory::factory classifier_factory;

/* ----------------- Tutorial -------------------------
Just like the Features.. 
*/

#endif
