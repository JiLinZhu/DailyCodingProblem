/* 50. Microsoft
Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5
You should return 45, as it is (3 + 2) * (4 + 5).
*/

int eval( int a, int b, string op) {
  switch(op) {
    case "+":
      return a + b;
    case "-":
      return a - b;
    case "*":
      return a * b;
    default:
      return a / b;
  }
}
 
int treeArith( Node* root ) {
  if( root->left == nullptr ) return (int)root->val;
  else return eval( treeArith(root->left), treeArith(root->right), root->val );
}