/**
 * @file 02-t.cpp
 * @author Jianer Cong
 * @brief test lru
 */

#include "02-LRU.cpp"

int main(int argc, char *argv[]){

  lru m(3);

  m.set(1,10); cout << m;
  m.set(2,20); cout << m;
  m.set(3,30); cout << m;
  m.set(4,40); cout << m;

  m.get(4); cout << m;
  m.get(2); cout << m;

  return 0;
  }
