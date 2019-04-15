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

class Solution {
public:
    TreeNode* rebuild(vector<int> preorder, int a, int lower, int higher ) {
        if( lower == higher ) return nullptr;
        
        
        TreeNode* root = new TreeNode(preorder[a]);
        
        int inOrderIndex = map[preorder[a]];
        root->left = rebuild(preorder, a+1, lower, inOrderIndex);
       
        root->right = rebuild(preorder, a+inOrderIndex-lower+1, inOrderIndex+1, higher);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        for( int i = 0; i < size; i++ )  map[inorder[i]] = i;
        
        return rebuild(preorder, 0, 0, size);
    }
private:
    unordered_map<int,int> map;
};

