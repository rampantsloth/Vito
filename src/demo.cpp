#include "demo.h"
#include <dlfcn.h>

using std::string;
using std::cout;
using std::endl;

//int ten = 0;

#include "ClassifierFactory.h"
#include "Exceptions.h"

#include "XMLPipelineFactory.h"
#include "BoostFileSystem.h"




using namespace vito;
using namespace vito::classification;
using namespace vito::features;

namespace vito{
class Dummy{};



void demo(){
  // ParameterDataSource::ptr xml( new XMLParameterDataSource ("parameters.xml"));
  // vito::FileSystem::ptr fs( new vito::BoostFileSystem());
  // vito::features::FeatureFactory ff(fs, FEATUREPLUGINDIR);
  // //vito::features::VisualFeatureAlgorithm::ptr feat =  ff.getAlgorithm("HoG");
  // //cout <<  feat->getName() << endl;
  // //std::string loc = "radialgrad.jpg";
  // //RgbImage image(loc);
  // //feat->extract(ImageAccess(DataPoint((size_t)0, loc, loc, loc)), &image);
  // //image.save("clooonebaby.jpg");
  // vito::classification::ClassifierFactory factory(fs,CLASSIFIERPLUGINDIR);
  // vito::classification::ClassifierAlgorithm::ptr aap = (factory.getAlgorithm("SVM", xml));

  //fs.getFilesOfType(".dylib", "./obj/FeaturePlugins/");
  FileSystem::ptr fs (new BoostFileSystem());
  FeatureFactory::ptr ff( new FeatureFactory(fs, "obj/ClassifierPlugins"));
  ClassifierFactory::ptr cf(new ClassifierFactory(fs, "obj/FeaturePlugins"));
  XMLPipelineFactory pipf;
  ClassifierNode cln = pipf.buildClassifier("pipeline.xml");
  classification::Classifier::ptr cl = cln.build(ff, cf);
  DataSet ds("./datasets/caltech101" ,fs);
  ds.setCategoryActivity("accordion", true);
  ds.setCategoryActivity("Motorbikes", true);
  cl->train(ds);
}

} // vito
