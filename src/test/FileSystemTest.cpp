//#define BOOST_TEST_MODULE FileSystem
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <vector>
#include "BoostFileSystem.h"

using namespace vito;
using std::vector;

BOOST_AUTO_TEST_CASE(FileSystemTest){
 FileSystem::ptr system( new BoostFileSystem());
 vector<float> vec;
 vec.reserve(1000);
 for(int i = 0; i < 1000; i++)
   vec.push_back(i);
 system->writeDescriptor(vec, "test.desc");
 vector<float> result = system->readDescriptor("test.desc");
 BOOST_CHECK(result.size() == 1000);
 for(int i = 0; i < 1000; i++){
   BOOST_CHECK(result[i] == vec[i]);
 }
}
