/*
Get the successor ( next node in order traversal )
*/

Node* successor( Node* cur ) {
  if( cur->right ) {
    Node* temp = cur->right;
    while(temp->left) temp = temp->left;
    return temp
  } else {
    while(cur->parent && cur->parent->left !== cur ) {
      cur = cur->parent;
    }
    return cur->parent;
  }
}
