#include "demo.h"

using std::string;
using std::cout;
using std::endl;

namespace vito{
class Dummy{};

void demo(){
  XMLParameterDataSource xmldsource("parameters.xml");
  boost::shared_ptr<Dummy> aap(new Dummy());
  //SP< Dummy > aap(new Dummy());
  //FeatureFactory ff;
  //ff.get("HoG", &xmldsource);
}

} // vito
