#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace vito{
namespace exception{

#define exc(name, parent, dummy)		\
  class name : public parent{			\
  virtual const char* what() const throw()	\
  {						\
    return dummy;				\
  }						\
  };						\


exc(Vito, std::exception, "general exception");
exc(ParametersEmpty, Vito, "no parameters found");
exc(Cache, Vito, "Something to do with the cache");
exc(CacheReadingError, Cache, "Could not read an element from the Cache");
exc(Plugins, Vito, "Problem to do with plugins");
exc(CouldNotInstantiateProblem, Plugins, "Could not instantiate a certain plugin");
exc(FileSystem, Vito, "Something to do with the files");
exc(FileNotFound, FileSystem, "a certain file has not been found");
exc(XML, FileSystem, "parameters node was not found inside the xml")
exc(NoInput, Vito, "no input was given to the classifiers");
exc(CategoryNotFound, Vito, "cannot find a given category");
exc(ClassifierNotFound, Plugins, "could not find a given classifier");
exc(FeatureNotFound, Plugins, "couldn ot find a particular features");
exc(CouldNotCreateClassifier, Plugins, "couldn't create a classifier");
} // exceptions
}// vito


#endif
