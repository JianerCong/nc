/**
 * @file 04-t.cpp
 * @author Jianer Cong
 * @brief Test the 2-Stack Queue
 */

#include "04-2stckQ.cpp"

int main(int argc, char *argv[]){

  Solution s;
  s.push(1);cout << s;
  s.push(2);cout << s;
  s.push(3);cout << s;
  s.pop();cout << s;
  s.push(4);cout << s;
  s.pop();cout << s;

  return 0;
  }
