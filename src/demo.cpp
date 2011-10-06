#include "demo.h"
#include <dlfcn.h>

using std::string;
using std::cout;
using std::endl;

//int ten = 0;

#include "ClassifierFactory.h"
#include "Exceptions.h"

namespace vito{
class Dummy{};



void demo(){
  ParameterDataSource::ptr xml( new XMLParameterDataSource ("parameters.xml"));
  vito::FileSystem::ptr fs( new vito::BoostFileSystem());
  vito::features::FeatureFactory ff(fs, xml, FEATUREPLUGINDIR);
  //vito::features::VisualFeatureAlgorithm::ptr feat =  ff.getAlgorithm("HoG");
  //cout <<  feat->getName() << endl;
  //std::string loc = "radialgrad.jpg";
  //RgbImage image(loc);
  //feat->extract(ImageAccess(DataPoint((size_t)0, loc, loc, loc)), &image);
  //image.save("clooonebaby.jpg");
  vito::classification::ClassifierFactory factory(fs, xml,CLASSIFIERPLUGINDIR);
  vito::classification::ClassifierAlgorithm::ptr aap = (factory.getAlgorithm("SVM"));

  //fs.getFilesOfType(".dylib", "./obj/FeaturePlugins/");

}

} // vito
