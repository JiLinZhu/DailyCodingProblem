/* 43. Amazon
Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.
Each method should run in constant time.
*/

class MaxStack {
public:
	void push(val) {
		normal.push(val);
		maxStack.push( maxStack.size() > 0 ? max(val, maxStack.top()) : val );
	}

	int pop() {
		if( normal.size() <= 0 ) return NULL;
		maxStack.pop();
		int temp = normal.top();
		normal.pop();
		return temp;
	}

private:
	stack<s> normal;
	stack<s> maxStack;
}

int MaxStack::max() {
	return maxStack.size() <= 0 ? NULL : maxStack.top();
}