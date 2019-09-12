/* 110. Facebook
Given a binary tree, return all paths from the root to leaves.

For example, given the tree

   1
  / \
 2   3
    / \
   4   5
*/

class Solution {
public:
  void rootToLeaf( Node* root, vector<int> cur ) {
    if(root == NULL) {
      result.push_back(cur);
      return;
    }
    cur.push_back(root->val);
    rootToLeaf(root->left, cur);
    rootToLeaf(root->right, cur);
  }
  // could also make this pass & and just delete the most recent index on return;

private:
  vector<vector<int>> result;
}
