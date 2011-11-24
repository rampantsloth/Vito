#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <map>
#include <list>

namespace vito{
template<class Object> class LRUCache{
public:
  typedef boost::shared_ptr<Object> ObjectPtr;
  typedef std::map< std::string, ObjectPtr > CacheMap;
  typedef std::vector<std::string> hashvec;
private:
  hashvec hashes;
  CacheMap cache_map;
  size_t maxentries, kEntries;
public:
  LRUCache(size_t max_size) :
    maxentries(max_size),
    kEntries(0){
  }

  void insert(std::string hash, ObjectPtr entry){
    for(hashvec::iterator i = hashes.begin(); 
	kEntries > maxentries - 1 && i != hashes.end(); ++i)
      if(cache_map[hash].unique()){
	cache_map.erase(hash);
	hashes.erase(i);
	i = hashes.begin();
      }
    hashes.push_back(hash);
    cache_map[hash] = entry;
    kEntries++;

  }

  ObjectPtr find(std::string hash){
    typename CacheMap::iterator descit = cache_map.find(hash);
    if(descit == cache_map.end())
      return ObjectPtr();
    else 
      return descit->second;
  }
};

}// vito



#endif
