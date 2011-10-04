#include "demo.h"
#include <dlfcn.h>

using std::string;
using std::cout;
using std::endl;

//int ten = 0;

namespace vito{
class Dummy{};

void demo(){
  ParameterDataSource::ptr xml( new XMLParameterDataSource ("parameters.xml"));
  vito::FileSystem::ptr fs( new vito::BoostFileSystem());
  vito::features::FeatureFactory ff(fs, xml);
  vito::features::VisualFeatureAlgorithm::ptr feat =  ff.getFeatureAlgorithm("HoG");
  cout <<  feat->getName() << endl;
  std::string loc = "radialgrad.jpg";
  RgbImage image(loc);
  feat->extract(ImageAccess(DataPoint((size_t)0, loc, loc, loc)), &image);
  image.save("clooonebaby.jpg");
  


  //fs.getFilesOfType(".dylib", "./obj/FeaturePlugins/");

}

} // vito
