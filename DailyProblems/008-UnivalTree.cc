/* 8. Google
A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
Given the root to a binary tree, count the number of unival subtrees
*/
pair<int, bool> univalTree( Node* root ) { // {# uni, cur root is uni}
	if( root == nullptr ) return {0, true};

	pair<int,bool> left = univalTree(root->left);
	pair<int,bool> right = univalTree(root->right);
	bool inc = true;
	if( root->left != nullptr && root->left->val != root->val ) inc = false;
	else if( root->right != nullptr && root->right->val != root->val ) inc = false;

	return { left.first + right.first + inc , left.second && right.second }
}