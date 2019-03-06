/* Google
Implement an LRU (Least Recently Used) cache. It should be able to be initialized with a cache size n, and contain the following methods:

set(key, value): sets key to value. If there are already n items in the cache 
and we are adding a new item, then it should also remove the least recently used item.

get(key): gets the value at key. If no such key exists, return null.
Each operation should run in O(1) time.
*/



class LRU {
  int maxSize;
  unordered_map<int, Node*> cache;
  Node* start;
  Node* end;

  void set( int key, int val ) {
    if( cache.find(key) != cache.end() ) {
      cache[key]->val = val;
      shiftToEnd(cache[key]);
    } else {
      Node* newNode = new Node(val);
      newNode->prev = end;
      end = newNode;
      cache[key] = newNode;
      if( cache.size() > maxSize ) {
        cache.erase(key);
        Node* temp = start;
        start = start->next;
        delete start;
      }
    }
  }  

  int get( int key ) {
    if( cache.find(key) == cache.end() ) return null;

    int val = cache[key]->val;
    shiftToEnd(cache[key]);
    return val;
  } 

  void shiftToEnd( Node* node ) {
    if( cache.size() == 1 ) return;
    if( node->prev ) {
      node->prev->next = node->next;
    } else {
      start = start->next;
    }
    if( node->next ) {
      node->next->prev = node->prev;
    } else {
      end = end->prev;
    }
    end->next = node;
    node->prev = end;
    node->next = null;
    end = node;
  }

};
