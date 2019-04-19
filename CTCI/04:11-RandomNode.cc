/*
Implemnt a binary tree class method that also supports getting a random node.

*/


class BinaryTree {
  Node* getIthNode(int i, Node* cur) {
    int leftSize = cur->leftSize;
    if( i == leftSize ) return cur;
    else {
      return i < leftSize ? getIthNode(i, cur->left) : getIthNode(i - leftSize - 1, cur->right);
    }
  }

  Node* getRandomNode() {
    int randInt = randint(root->leftSize + root->rightSize + 1); // generate a number from 0 to x - 1
    return getIthNode(randInt, root);
  }

private:
  Node* root;
};
