#include "PluginLoader.h"

#include <dlfcn.h>
#include <iostream>

//vito::FeaturePluginLoader::factory feature_factory;

using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace vito{

PluginLoader::PluginLoader(filelist list){
  //load every plugin file
  for(filelist::iterator i = list.begin(); i != list.end(); ++i){
    loadPlugin(*i);
  }
}

void PluginLoader::loadPlugin(string dylib_location){
  cout << "loading: " << dylib_location << endl;
  dylib_location = "./" + dylib_location;
  void *handle = dlopen(dylib_location.c_str(), RTLD_NOW);
  if(handle)
    handles.push_back(handle);
  else{
    cout << "could not read " << dylib_location << " !!!" << endl;
    cout << "error is: \n\t" <<  dlerror() << endl;
  }
}

PluginLoader::~PluginLoader(){
  for(vector<void*>::iterator i = handles.begin(); i != handles.end(); ++i)
    dlclose(*i);
}

} // namespaces
