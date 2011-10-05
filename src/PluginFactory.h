#ifndef PLUGINFACTORY_H
#define PLUGINFACTORY_H

#include "FileSystem.h"
#include "ParameterDataSource.h"
#include "PluginLoader.h"
#include <iostream>

namespace vito{

template <class Type> class PluginFactory {
public: 
  typedef boost::shared_ptr<Type> maker(vito::ParameterDataSource::const_ptr);
  typedef std::map<std::string, maker*, std::less<std::string> > factory;
protected:
  FileSystem::ptr filesystem;
  ParameterDataSource::ptr default_dsource;
  PluginLoader loader;
  virtual const factory &getFactory() const = 0;
public:

  PluginFactory(FileSystem::ptr fs,
		ParameterDataSource::ptr dsource,
		std::string plugin_directory) :
    filesystem(fs), default_dsource(dsource), 
    loader(filesystem->getFilesOfType(".dylib", plugin_directory)){}
  
  boost::shared_ptr<Type> getAlgorithm(std::string algorithm_name,
		    ParameterDataSource::const_ptr dsource = 
		    ParameterDataSource::const_ptr()){
    if(dsource == NULL)
      dsource = default_dsource;
    const factory &cfactory = getFactory();
    if(cfactory.count(algorithm_name))
      return (*cfactory.find(algorithm_name)).second(dsource);
    else
      std::cout << "could not find " << algorithm_name
		<< " in the plugins" << std::endl;
    return boost::shared_ptr<Type>();
  }
};

}

#endif
