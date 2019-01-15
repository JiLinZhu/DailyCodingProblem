/* 6. Google
An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. 
Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
*/

struct Node {
	int val;
	Node* both;
}

struct XORLinkedList {
	Node* begin;
	Node* end;
};

void add( int val ) {
	Node* newNode = new Node();
	newNode->val = val;
	newNode->both = xor(NULL, end);
	if( end != NULL ) {
		end->both = xor(xor(NULL, end->both), newNode);
	}
	end = newNode;
}

Node* get( int index ) {
	Node* result = begin;
	Node* prev = NULL;
	Node* temp;
	for(int i = 0; i < index; i++) {
		temp = result;
		result = xor(prev, result->both);
		prev = temp;
	}
	return result;
}