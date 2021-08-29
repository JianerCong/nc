/**
 * @file 05-2find.cpp
 * @author Jianer Cong
 * @brief binary search a number in an array.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#define DOWN_H while (nums[h-1] == nums[h]){    \
    h--;                                        \
  }

#define UP_L while (nums[l+1] == nums[l]){      \
    l++;                                        \
  }
class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   * 如果目标值存在返回下标，否则返回 -1
   * @param nums int整型vector 
   * @param target int整型 
   * @return int整型
   */
  static int search(const vector<int>& nums, int target) {

    if (nums.empty())
      return -1;

    if (nums.size() == 1)
      return (nums[0] == target)? 0 : -1;

    // write code here
    int l{0};
    int h{ nums.size()-1};                  // lower and higher boundaries
    DOWN_H;
    UP_L;

    // the index to search
    int i;
    for (i = h / 2;;){

      // One issue is that you will never get to h by trancated division. So we
      // need to manually check that.
      if (l == h - 1){
        cout << "l is h-1 already. Last chance: ";
        if (nums[h] == target){
          cout << "Last number yes.\n";
          return h;
        }else if(nums[l] == target){
          cout << "First number yes.\n";
          return l;
        }else{
          cout << "Nope\n";
          break;
        }
      }
      // h - l > = 2

      if (nums[i] > target){
        cout << "Move h to left since " << nums[i] << " > "
             << target << endl;

        h = i;

        // Skip repeating values
        DOWN_H;
      }else if (nums[i] < target){
        cout << "Move l to right since " << nums[i] << " < "
             << target << endl;

        l = i;

        // Skip repeating values
        UP_L;
      }else{
        cout << "Value found at " << i << endl;
        while(nums[i-1] == nums[i]){
          cout << ":arrow_backward:";
          i--;
        }
        cout << "Value to be returned " << i << endl;
        return i;
      }

      // It is possible that l has incremented too much
      // for repeating values.
      cout << "Now l is " << l << " and h is "
           << h << endl;
      if (l >= h)
        break;


      // Time to assign new i.
      i = (l + h)/ 2;
      cout << " i is " << i << endl;
    }
    cout << "Value not found\n";
    return -1;
  }
};
