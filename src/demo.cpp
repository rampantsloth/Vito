#include "demo.h"

using std::string;
using std::cout;
using std::endl;

namespace vito{

void demo(){
  SP<ParameterDataSource> datasource = new XMLParameterDataSource("parameters.xml");
  cout << "pars: " << datasource->get("HoG", "orientations", (double) 5);
}

} // vito
