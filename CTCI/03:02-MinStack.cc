/*
Design a data structure that in addition to a normal stack functionalities, can get the min.
*/


class MinStack {
private:
  stack<int> nums;
  stack<int> mins;

public:

  int top() {
    if(nums.empty()) return INT_MIN;
    return nums.top();
  }

  void pop() {
    if(nums.empty()) return;
    nums.pop();
    mins.pop();
  }

  void push(int i) {
    nums.push(i);
    mins.push(min(i, mins.top()));
  }

  void min() {
    if(mins.empty()) return;
    return mins.top();
  }
};

// We could also make this a bit more efficient if we only pushed stuff that was < min and only popped when the nums.top() == mins.top()
