#include "XMLParameterDataSource.h"

#include "tinyxml/tinyxml.h"
#include <boost/lexical_cast.hpp>

using std::string;
using std::cout;
using std::endl;

namespace vito{

XMLParameterDataSource::XMLParameterDataSource(string location){
  // load the document
  TiXmlDocument document(location.c_str());
  if(!document.LoadFile()){
    cout << "could not find " << location << endl;
    return;
  }
  // find the parameters child
  TiXmlNode *parameterNode = 0;
  bool found = false;
  cout << "about to iterate" << endl;
  while(!found && (parameterNode = document.IterateChildren(parameterNode))){
    if((string) parameterNode->Value() == "parameters"){
      found = true;
    }
  }
  cout << "done iterating " << endl;
  if(!found){
    cout << "could not find parameters in " << location << endl;
    return;
  }
  cout << parameterNode << endl;
  cout << parameterNode->Value() << endl;
  // iterate each parameter group
  TiXmlNode *pGroup = 0;
  while((pGroup = parameterNode->IterateChildren(pGroup))){
    cout << "doing parametergroup: " << pGroup->Value() << endl;
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
	    boost::lexical_cast<int>(cPar->ToElement()->GetText()));
      else if(cAttribute == "uint")
	add(pGroup->Value(), cPar->Value(),
	    boost::lexical_cast<size_t>(cPar->ToElement()->GetText()));
      else if(cAttribute == "double")
	add(pGroup->Value(), cPar->Value(), 
	    boost::lexical_cast<double>(cPar->ToElement()->GetText()));
    }
  }
}


}
