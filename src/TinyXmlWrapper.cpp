#include "TinyXmlWrapper.h"
#include "Exceptions.h"

using std::string;

namespace vito{

TiXmlNode * TinyXMLWrapper::findChild(TiXmlNode *parent, 
				      string childname, 
				      bool required){
  TiXmlNode *child = 0;
  bool found = false;
  while(!found && (child = parent->IterateChildren(child)))
    if((string) child->Value() == childname)
      found = true;
  if(!found) 
    if(required) throw exception::XML();
    else child = 0;

  return child;
}

}
