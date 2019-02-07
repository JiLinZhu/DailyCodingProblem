/* 36. Dropbox
Given the root to a binary search tree, find the second largest node in the tree.
*/

Node* secondLargest( Node* root ) {
	if( root == NULL ) return NULL;

	stack<Node*> s;
	Node* cur = root;
	while( cur != NULL ) {
		s.push(cur);
		cur = cur->right;
	}

	cur = s.top();
	s.pop();
	if( cur->left == NULL ) return s.top();
	else {
		cur = cur->left;
		while( cur->right != NULL ) cur = cur->right;
		return cur;
	}
	return NULL;
}

void secondLargestUtil(Node *root, int &c) { // Kinda cheating way
    if (root == NULL || c >= 2) 
        return; 

    secondLargestUtil(root->right, c); 
    c++; 
    if (c == 2) { 
        cout << root->key << endl; 
        return; 
    } 
    secondLargestUtil(root->left, c); 
} 