#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <vector>
#include "sharedpointer.h"


namespace vito{

/* open and closes dylibs that are assumed to contain plugins */
class PluginLoader{
private:
  std::vector< void* > handles;
  void loadPlugin(std::string dylib_location);
public:
  typedef std::vector<std::string> filelist;
  PluginLoader(filelist list);
  ~PluginLoader();
};

} // vito
#endif
