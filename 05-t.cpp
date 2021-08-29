/**
 * @file 05-t.cpp
 * @author Jianer Cong
 * @brief try binary search
 */

#include "05-2find.cpp"


int main(int argc, char *argv[]){
  cout << "Search 2 in {1 2}\n";
  Solution::search({1,2},2);
  cout << "Search 2 in {2 3}\n";
  Solution::search({2,3},2);
  return 0;
  }
