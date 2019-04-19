/*
Given two nodes, find the first common ancestor of the two,
Avoid storing nodes in an additonal data structure.
*/


Node* firstCommonAncestor( Node* cur, Node* a, Node* b ) {
  if(cur == NULL) return NULL;
  if( cur == a || cur == b ) return cur;
  Node* left = firstCommonAncestor(cur->left);
  Node* right = firstCommonAncestor(cur->right);

  if(left != NULL && right != NULL) {
    return cur;
  } else if ( left != NULL ) {
    return left;
  } else if ( right != NULL ) {
    return right;
  } else {
    return NULL;å
  }
}
