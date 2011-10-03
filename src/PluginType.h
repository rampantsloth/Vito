#ifndef PLUGINTYPE_H
#define PLUGINTYPE_H

#include "sharedpointer.h"
#include "ParameterDataSource.h"

namespace vito{

template <class Type> class PluginType{
public:
  typedef SP<Type> maker(vito::ParameterDataSource*);
  typedef std::map<std::string, maker*, std::less<std::string> > factory;
};

} // namespace vito

#endif
