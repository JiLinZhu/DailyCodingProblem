/* 53. Apple
Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) 
data structure with the following methods: enqueue, which inserts an element into the queue, 
and dequeue, which removes it.
*/

class QueueWithStacks {
  stack<int> s;
  stack<int> q;

  /** Push element x to the back of queue. */
  void push(int x) {
    s.push(x);
  }
  
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int temp = this->peek();
    q.pop();
    return temp;
  }

  /** Get the front element. */
  int peek() {
    int temp;
    if( q.empty() ) {
      while(!s.empty()) {
        temp = s.top();
        s.pop();
        q.push(temp);
      }
    }
    temp = q.top();
    return temp;
  }
}