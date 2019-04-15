/*
Given a sorted array, create a binary serach tree with minimal height
*/


Node* minimalTree(vector<int> x, int lower, int higher) {
  if(lower > higher) return NULL;

  int mid = lower + (higher-lower)/2;
  Node* newNode = new Node(x[mid]);
  newNode->left = minimalTree(x, lower, mid-1);
  newNode->right = minimalTree(x, mid+1, higher);
  return newNode;
}
