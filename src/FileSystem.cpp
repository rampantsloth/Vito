#include "FileSystem.h"

#include <fstream>
#include <iostream>
#include <math.h>

using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios;


namespace vito{

vector<float>& FileSystem::writeDescriptor(vector<float> &datapoints, string destination){
  size_t elements = datapoints.size();
  ofstream file (destination.c_str(), ios::out | ios::binary); 
  // write the size
  file.write(reinterpret_cast<char *>
	     (&elements),
	     sizeof(elements));
  // write the elements
  for(vector<float>::iterator i = datapoints.begin(); 
      i != datapoints.end(); ++i)
    file.write(reinterpret_cast<char *>
	       (&*i) ,
	       sizeof(float));
  file.close();
  return datapoints;
}

vector<float> FileSystem::readDescriptor(string location){
  vector<float> datapoints;
  size_t elements;
  ifstream file (location.c_str(), ios::in | ios::binary); 
  file.read(reinterpret_cast<char *>
	    (&elements),
	    sizeof(elements));
  datapoints.resize(elements);  
  for(vector<float>::iterator i = datapoints.begin(); 
      i != datapoints.end(); ++i)
    file.read(reinterpret_cast<char *>
	      (&*i),
	       sizeof(float));
  file.close();
  return datapoints;
  }


} // vito

