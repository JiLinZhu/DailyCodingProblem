/* 89. LinkedIn
A binary search tree is a tree with two children, left and right, and satisfies the constraint
that the key in the left child must be less than or equal to the root and the key in the right child must be greater than or equal to the root.
*/

bool validBST(Node* root, int min, int max) {
  if( root == nullptr ) return true;

  if( root->val < min || root->val > max ) return false;

  return validBST(root->left, min, root->val) && validBST(root->right, root->val+1, max);
}
