/* 80. Google
Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.

    a
   / \
  b   c
 /
d
*/

Node* deepestNode( Node* root ) {
  queue<Node*> q;
  Node* cur;
  q.push(root);
  while(!q.empty()) {
    cur = q.pop();
    if(cur->left) q.push(cur->left);
    if(cur->right) q.push(cur->right);
  }
  return cur;
}
