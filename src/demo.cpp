#include "demo.h"

using std::string;
using std::cout;
using std::endl;


std::map<string, FeatureMaker *, less<string> > factory;
namespace vito{

#define bla(arg) \
  std::cout << #arg << std::endl;




void demo(){
  void *hndl = dlopen("obj/FeaturePlugins/HoGPlugin.dylib", RTLD_NOW);
  if(hndl == NULL){
    cerr << dlerror() << endl;
    exit(-1);
  }
  cout << factory.size() << endl;
  void *mkr = dlsym(hndl, "doIt");
  SP<features::VisualFeatureAlgorithm> a = factory["HoG"](0);
  //string parameterfile = "parameters.xml";
  //Settings settings(parameterfile);
  //Dataset dset = DatasetFactory("abdullah2010").;
  bla(int ikkelspikkel);
  /*
  string location = "images.png";
  features::HoGParameters p;
  p.blur = true;
  p.blur_size = 5;
  p.xhistograms = 3;
  p.yhistograms = 3;
  p.orientations = 6;
  features::HoG hog(p);
  SP<RgbImage> rg = new RgbImage(location);
  Descriptor result = hog.extract(DataPoint(0,"bla", location, "cool"), rg);
  rg->save("justdone.jpg");
  */
}

} // vito
