#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <list>

namespace vito{
template<class Entry> class LRUCache{
private:
  typedef std::pair<std::string, Entry> EntryPair;
  typedef std::list< EntryPair > CacheList;
  typedef std::map< std::string, EntryPair* > CacheMap;

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
    cache_map[hash] = entry;
    if(kEntries > maxentries){
      cache_map.erase(cache_list.front.first);
      cache_list.pop_back();
      kEntries--;
    }
  }
  CacheMap* find(std::string hash){
    return cache_map.find(hash);
  }
};

}// vito



#endif
