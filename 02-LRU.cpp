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
using std::ostream;
typedef vector<int> vi;

/**
 * @brief the lru cache object
 */
class lru {
public:
  map<int,int> m;               //<! the container.
  list<int> l;                  //<! the queue of key to remove
  const int size = 0;                 //<! the size of array

  lru(int s): size(s) {};
  void prioritize(int k){
    l.remove(k); l.push_back(k);
  }
  void add(int k,int v){
    m[k] = v;
    l.push_back(k);
  }

  friend ostream& operator<<(ostream & os , lru o);

  /**
   * @brief insert a key-value pair.
   *
   * @param k key
   * @param v value
   */
  void set(int k, int v);

  int get(int k){
    cout << "Getting value for key " << k << endl;
    map<int,int>::iterator i = m.find(k);
    if (i == m.end()){
      cout << "\tKey not foundn 🙉";
      return -1;
    }else{
      cout << "\tKey found:+1: to be " << i->second << endl;
      prioritize(i->first);
      return i->second;
    }
  }
};

#include "02-LRU-i.cpp"

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


