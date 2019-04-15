/*
Check if a binary tree is a BST
*/

bool validBST(Node* root, int min, int max) {
  if( root == nullptr ) return true;

  if( root->val < min || root->val > max ) return false;

  return validBST(root->left, min, root->val) && validBST(root->right, root->val+1, max);
}
