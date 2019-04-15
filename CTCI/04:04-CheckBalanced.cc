/*
Check if a binary tree is balanced.
*/


int checkBalanced(Node* root) {
  if( root == NULL ) return 0;

  int left = checkBalanced(root->left);
  if(left == -1) return -1;
  int right = checkBalanced(root->right);
  if(right == -1) return -1;
  if(abs(right - left) > 1 ) return -1;

  return max(left->first, right->first) + 1;
}
