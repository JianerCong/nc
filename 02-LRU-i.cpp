/**
 * @file 02-LRU-i.cpp
 * @author Jianer Cong
 * @brief Implement the LRU cache.
 */



ostream& operator<<(ostream & os , lru o){
  cout << "Now this is a size " << o.size <<" LRU Cache:\n"
       << "\t stored map:\n";

  for (auto & [k,v] : o.m){
    cout << "k : " << k << " : " << v << endl;
  }

  cout << "\t stored vector:\n";
  for (auto & x : o.l ){
    cout << x << " ";
  }

  cout << endl;

  return os;
}


void lru::set(int k, int v)
{
  cout << "Setting value for " << k << " : " << v << endl;
  // If k already exits
  map<int,int>::iterator i = m.find(k);
  if (i != m.end()){
    cout << "\tKey exits, change value.\n";
    // change value
    i->second = v;
    // Prioritize this key
    prioritize(k);
  }else{
    cout << "\tKey dosn't exits. Add new value.";
    // need to push k into map
    if (m.size() == size){
      cout << "\tCache is full. Remove " << l.front() << endl;
      // need to pop something
      m.erase(l.front());
      l.pop_front();
      add(k,v);
    }else{
      cout << "\tStack not full, add it directly.\n";
      // map not full, new key.
      add(k,v);
      // size++;
    }
  }
}
