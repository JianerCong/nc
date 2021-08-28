/**
 * @file 03-lpls.cpp
 * @author Jianer Cong
 * @brief Check if the list has loop.
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    // Two pointer: one fast, one slow.
    ListNode *f, *s;
    // If there is a circle, then one day two pointer will meet.

    // Init
    f = s = head;
    while(f){
      // If f is NULL -> end of the list -> game over

      // Increment f twice.
      f = f->next;
      if (f)
        f = f->next;
      else
        break;

      // Increment s once.
      s = s->next;

      // Compare
      if (f == s)
        return true;            // Yes, has circle
    }
    return false;               // Nope, no circle.
  }
};
