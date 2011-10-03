#include "demo.h"

using std::string;
using std::cout;
using std::endl;

namespace vito{

void demo(){
  XMLParameterDataSource xmldsource("parameters.xml");
  FeatureFactory ff;
  ff.get("HoG", &xmldsource);
}

} // vito
