/* 3. Google
Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
*/

string serialize( Node* root ) {
	if (root == nullptr) return "#";
	return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
}

TreeNode* deserialize(string& data) {
	if (data[0]=='#') {
	    if(data.size() > 1) data = data.substr(2);
	    return nullptr;
	} else {
	    TreeNode* node = new TreeNode(helper(data));
	    node->left = mydeserialize(data);
	    node->right = mydeserialize(data);
	    return node;
	}
}

int helper(string& data) {
	int pos = data.find(',');
	int val = stoi(data.substr(0,pos));
	data = data.substr(pos+1);
	return val;
}