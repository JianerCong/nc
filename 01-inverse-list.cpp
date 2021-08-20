                                                \
#include <iostream>
using std::cout;
using std::endl;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x = 0) :
    val(x), next(NULL) {
	}
};

void show(ListNode * n){
  int max = 0;
  while(n){
    cout << n->val << " ";
    n = n-> next;
  }
  cout << endl;
}

class Solution {
public:
  static ListNode* ReverseList(ListNode* pHead) {
    if (!pHead)                 //empty list
      return NULL;

    if (!pHead->next)           //one-element list
      return pHead;

    ListNode *pn, *pm;          //new head and mover
    pn = pHead;
    pm = pHead->next;
    pHead = pm->next;

    pn->next = NULL;            // KEY: to remove the old head.
    while (pm){             //While there's next to move
      pm->next = pn;         //cut and move
      pn = pm;               //new head proceed
      pm = pHead;            //ready to move next
      if (pHead)
        pHead = pHead -> next;  //try search next to move
    }
    return pn;
  }
};

#define N 3

int main(int argc, char *argv[]){
  ListNode n[N];
  for (int i =0; i < N-1; i++){
    n[i].val = i;
    n[i].next = n + i + 1;
  }
  n[N-1].val = N-1;

  show(n);
  ListNode *p = Solution::ReverseList(n);
  show(p);
  return 0;
  }
