#include <iostream>
#include <stack>


using std::cout;
using std::endl;
using std::stack;
using std::ostream;


/**
 * @file 04-2stckQ.cpp
 * @author Jianer Cong
 * @brief Implement a queue with two stacks.
 *
 * Two stacks. One simulates the "head" of a queue, and the other the "tail" of
 * the queue.
 */

class Solution
{
public:
  friend ostream & operator<<(ostream & os, Solution & s);
  /**
   * @brief Enqueue an item.
   * @param node the item to be added.
   */
  void push(int node) {
      cout << "Pushing to stack 1\n";
      stack1.push(node);
  }

  /**
   * @brief dequeue
   */
  int pop() {
    cout << "Need to pop from s2: ";
    if (stack2.empty()){
      cout << "s2 empty, pour s1 to s2 before pop\n";

      while (!stack1.empty()){
        stack2.push(stack1.top());
        stack1.pop();
      }

    }else{
      cout << "stack2 has something to pop\n";
    }
    int r = stack2.top();
    stack2.pop();
    cout << "Value poped is : " << r << endl;
    return r;
  }

private:
  stack<int> stack1;            // <! the IN
  stack<int> stack2;            //<! the OUT
};


// Display a stack
template <typename Stack>
void print(Stack stack /* pass by value */, int id)
{
  std::cout << "stack" << id << " [" << stack.size() << "]: ";
  for (; !stack.empty(); stack.pop())
    std::cout << stack.top() << ' ';
  std::cout << (id > 1 ? "\n\n" : "\n");
}


ostream & operator<<(ostream & os, Solution & s)
{
  cout << "The Current state:\n";
  print(s.stack1,1);
  print(s.stack2,2);

  return os;
}

