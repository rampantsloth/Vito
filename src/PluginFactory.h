#ifndef PLUGINFACTORY_H
#define PLUGINFACTORY_H

#include "FileSystem.h"
#include "ParameterDataSource.h"
#include "PluginLoader.h"
#include <iostream>

#include "Exceptions.h"

namespace vito{

template <class Type> class PluginFactory {
public: 
  typedef boost::shared_ptr<PluginFactory<Type> > ptr;
  typedef boost::shared_ptr<Type> maker(vito::ParameterDataSource::ptr);
  typedef std::map<std::string, maker*, std::less<std::string> > factory;
protected:
  FileSystem::ptr filesystem;
  PluginLoader loader;
  virtual const factory &getFactory() const = 0;
public:

  PluginFactory(FileSystem::ptr fs,
		std::string plugin_directory) :
    filesystem(fs), 
    loader(filesystem->getFilesOfType(".dylib", plugin_directory)){}
  
  boost::shared_ptr<Type> getAlgorithm(std::string algorithm_name,
				       ParameterDataSource::ptr dsource){
    std::cout << "knows where to find this " << std::endl;
    if(dsource == NULL)
      throw exception::ParametersEmpty();
    const factory &cfactory = getFactory();
    boost::shared_ptr<Type> alg();
    if(cfactory.count(algorithm_name))
      return (*cfactory.find(algorithm_name)).second(dsource);
    else
      throw exception::CouldNotInstantiateProblem();
    return boost::shared_ptr<Type>();
  }

  bool  exists(std::string str){
    return getFactory().count(str);
  }
};

}

#endif
