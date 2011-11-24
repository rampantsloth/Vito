#include "XMLParameterDataSource.h"

#include <boost/lexical_cast.hpp>

using std::string;
using std::cout;
using std::endl;

#include "Exceptions.h"

namespace vito{



XMLParameterDataSource::XMLParameterDataSource(string location){
  // load the document
  TiXmlDocument document(location.c_str());
  if(!document.LoadFile()){
    throw exception::FileNotFound();
  }
  // find vito child
  TiXmlNode *vitoNode = findChild(&document, "vito");
  TiXmlNode *parameterNode = findChild(vitoNode, "parameters");
  // iterate each parameter group
 
    extractParameters(parameterNode);    
  
}

XMLParameterDataSource::XMLParameterDataSource(TiXmlNode *pGroup){
  extractParameters(pGroup);
}

void XMLParameterDataSource::extractParameters(TiXmlNode *parameterNode){
 TiXmlNode *pGroup = 0;
  while((pGroup = parameterNode->IterateChildren(pGroup))){
    // iterate each parameter
    TiXmlNode *cPar = 0; // current parameter
    while((cPar = pGroup->IterateChildren(cPar))){
      //save it to the appropriate map
      string cAttribute;
      if(cPar->ToElement()->Attribute("type"))
	cAttribute = cPar->ToElement()->Attribute("type");
      if(cAttribute == "bool")
	add(pGroup->Value(), cPar->Value(), 
	    (boost::lexical_cast<bool>(cPar->ToElement()->GetText())));
      else if(cAttribute == "int")
	add(pGroup->Value(), cPar->Value(),
	    (int)boost::lexical_cast<double>(cPar->ToElement()->GetText()));
      else if(cAttribute == "uint")
	add(pGroup->Value(), cPar->Value(),
	    (size_t) boost::lexical_cast<double>(cPar->ToElement()->GetText()));
      else if(cAttribute == "double")
	add(pGroup->Value(), cPar->Value(), 
	    boost::lexical_cast<double>(cPar->ToElement()->GetText()));
    }
  }
  
}


}
