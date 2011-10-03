#ifndef PLUGINTYPE_H
#define PLUGINTYPE_H

#include "sharedpointer.h"
#include "ParameterDataSource.h"
#include "boost/shared_ptr.hpp"


namespace vito{

template <class Type> class PluginType{
public:
  typedef boost::shared_ptr<Type> maker(vito::ParameterDataSource::const_ptr);
  typedef std::map<std::string, maker*, std::less<std::string> > factory;
};

} // namespace vito

#endif
