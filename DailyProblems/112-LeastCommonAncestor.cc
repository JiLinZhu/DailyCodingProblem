/* 112. Twitter
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. Assume that each node in the tree also has a pointer to its parent.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes v and w as the lowest node
in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
*/

Node* leastCommonAncestor(Node* root, Node* a, Node* b) {
  if(!root) return NULL;
  if( root == a || root == b ) return root;

  Node* left = leastCommonAncestor(root->left, a, b);
  Node* right = leastCommonAncestor(root->right, a, b);

  return left && right ? root : left || right;
}
