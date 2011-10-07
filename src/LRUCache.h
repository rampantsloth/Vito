#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <map>
#include <list>

namespace vito{
template<class Entry> class LRUCache{
public:
  typedef std::pair<std::string, Entry> EntryPair;
  typedef std::list< EntryPair > CacheList;
  typedef std::map< std::string, Entry* > CacheMap;
private:
  CacheList cache_list;
  CacheMap cache_map;
  size_t maxentries, kEntries;
public:
  LRUCache(size_t max_size) :
    maxentries(max_size),
    kEntries(0){
  }

  void insert(std::string hash, Entry entry){
    cache_list.push_front(std::make_pair(hash, entry));
    kEntries++;
    cache_map[hash] = &cache_list.begin()->second;
    if(kEntries > maxentries){
      cache_map.erase(cache_list.back().first);
      cache_list.pop_back();
      kEntries--;
    }
  }
  Entry find(std::string hash){
    
    if(cache_map.count(hash))
      return *cache_map[hash];
    else 
      return Entry();
  }
};

}// vito



#endif
