#ifndef XMLPARAMETERDATASOURCE_H
#define XMLPARAMETERDATASOURCE_H

#include "TinyXMLWrapper.h"
#include "ParameterDataSource.h"
#include <iostream>

namespace vito{

class XMLParameterDataSource : public ParameterDataSource,
			       private TinyXMLWrapper{
public:
       XMLParameterDataSource(std::string location);
  XMLParameterDataSource(TiXmlNode *pGroup);
  void extractParameters(TiXmlNode *pGroup);
};

}

 
#endif
