


int pathsWithSum(Node* root, unordered_map<int, int> sumsSoFar, int sum, int target) {
  if(root == NULL) return 0;
  sum += root->val;

  int result = sumsSoFar[sum - target];
  sumsSoFar[sum]++;
  return result + pathsWithSum(root->left, sumsSoFar, sum, target) + pathsWithSum(root->right, sumsSoFar, sum, target);
}


unordered_map<int,int> sumsSoFar;
sumsSoFar[0] = 1;
pathsWithSum(root, sumsSoFar, sum, target)
