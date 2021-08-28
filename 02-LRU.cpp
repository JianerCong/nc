/**
 * @file 02-LRU.cpp
 * @author Jianer Cong
 * @brief implement an LRU cache
 */

#include <iostream>
#include <map>
#include <vector>
#include <list>



using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::map;
typedef vector<int> vi;

/**
 * @brief the lru cache object
 */
class lru {
public:
  map<int,int> m;               //<! the container.
  list<int> l;                  //<! the queue of key to remove
  int size = 0;                 //<! the size of array
  lru(int s): size(s) {};
  void prioritize(int k){
    l.remove(k); l.push_back(k);
  }
  void add(int k,int v){
    m[k] = v;
    l.push_back(k);
  }

  /**
   * @brief insert a key-value pair.
   *
   * @param k key
   * @param v value
   */
  void set(int k, int v){
    // If k already exits
    map<int,int>::iterator i = m.find(k);
    if (i != m.end()){
      // change value
      i->second = v;
      // Prioritize this key
      prioritize(k);
    }else{
      // need to push k into map
      if (m.size() == size){
        // need to pop something
        m.erase(l.front());
        l.pop_front();
        add(k,v);
      }else{
        // map not full, new key.
        add(k,v);
        size++;
      }
    }
  }

  int get(int k){
    map<int,int>::iterator i = m.find(k);
    if (i == m.end()){
      return -1;
    }else{
      prioritize(i->first);
      return i->second;
    }
  }
};

class Solution {
public:
  /**
   * lru design
   * @param operators int整型vector<vector<>> the ops
   * @param k int整型 the k
   * @return int整型vector
   */
  vector<int> LRU(vector<vector<int> >& operators, int k) {
    // write code here
    lru V(k);
    vi o;                       //<! the output.
    for (vi r : operators)     // for each request
      {
        if (r[0] == 1)
          V.set(r[1],r[2]);
        else
          o.push_back(V.get(r[1]));
      }
    return o;
  }
};


int main(int argc, char *argv[]){
  
  return 0;
  }
