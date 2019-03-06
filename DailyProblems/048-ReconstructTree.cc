/* 48. Google
Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

    a
   / \
  b   c
 / \ / \
d  e f  g

*/

keep going right until seen
set

Node* reconstructTree( vector<char> preOrder, vector<char> inOrder, int a, int b) {
	Node* root = new Node(preOrder[a++]);
	stack<Node*> s;
	s.push(root);
	bool isLeft = preOrder[a] != inOrder[b];

	while(  ) {
		Node* cur = s.top();
		Node* newNode = new Node(preOrder[a]);

		if( isLeft ) {
			cur->left = newNode;
		} else {
			cur->right = newNode;		
		}

		s.push(newNode);
		isLeft = inOrder[b] != preOrder[a];


	}
}

