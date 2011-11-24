#ifndef XMLPIPELINEFACTORY_H
#define XMLPIPELINEFACTORY_H

#include "XMLParameterDataSource.h"
#include "Classifier.h"
#include "FeatureFactory.h"
#include "ClassifierFactory.h"
#include "Pipeline.h"

namespace vito{

class XMLPipelineFactory: private TinyXMLWrapper{
public:
   ClassifierNode buildClassifier(std::string file_location);
private:
  ClassifierNode buildClassifier(TiXmlNode *classifierNode);
  InputNode buildInput(TiXmlNode *inputNode);					
};

}

#endif
