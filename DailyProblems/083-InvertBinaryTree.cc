/* 83. Google
Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f
should become:

  a
 / \
 c  b
 \  / \
  f e  d
*/


Node* invertBinaryTree(Node* root) {
  if(root == NULL) return NULL;
  Node* temp = root->left;
  root->left = invertBinaryTree(root->right);
  root->right = invertBinaryTree(temp);
  return root;
}
