#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::copy;
using std::vector;
using std::ostream_iterator;

typedef vector<int> vi;
typedef ostream_iterator<int> oi;

int main(int argc, char *argv[]){
  vi v;
  oi o(cout,", ");
  for (int i = 0; i < 3; i++)
    v.push_back(i);

  cout << "Showing v: ";
  copy(v.begin(), v.end(), o);
  cout << endl;

  return 0;
  }
