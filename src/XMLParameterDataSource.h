#ifndef XMLPARAMETERDATASOURCE_H
#define XMLPARAMETERDATASOURCE_H

#include "ParameterDataSource.h"
#include <iostream>


namespace vito{

class XMLParameterDataSource : public ParameterDataSource{
public:
  XMLParameterDataSource(std::string location);
};

}

 
#endif
