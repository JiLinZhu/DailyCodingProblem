/*
Sort a stack using only an additional stack
*/

void sortStack(stack<int> &s) {
  int cur;
  stack<int> temp;

  while(!s.empty()) {
    cur = s.pop();
    while( temp.empty() || cur < temp.top() ) {
      s.push(temp.pop());
    }
    temp.push(cur);
  }

  while(!temp.empty()). s.push(temp.pop());
}
