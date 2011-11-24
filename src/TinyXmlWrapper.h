#ifndef   TINYXMLWRAPPER_H
#define   TINYXMLWRAPPER_H

#include <string>
#include "tinyxml/tinyxml.h"

namespace vito{

class TinyXMLWrapper{
protected:
  TiXmlNode *findChild(TiXmlNode *parent, 
		       std::string childname, 
		       bool required = true);
};
 
}

#endif 
