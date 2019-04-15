/*
Implement a Queue using Stacks.
*/



class QueueViaStacks {
private:
  stack<int> s;
  stack<int> q;


  void shift() {
    while(!s.empty()) {
      q.push(s.pop());
    }
  }

  void insert(int i) {
    s.push(i);
  }

  int top() {
    if(!q.empty()) return q.top();
    shift();
    return q.empty() ? INT_MIN: q.top();
  }

  void pop() {
    if(!q.empty()) return q.pop();
    shift();
    return q.empty() ? INT_MIN: q.pop();
  }

  bool empty() {
    return q.empty() && s.empty();
  }
}
