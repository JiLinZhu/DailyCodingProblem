/*
Given a binary tree, create a list of linked lists for each height
*/

class LinkedListNode {
  Node* node;
  LinkedListNode* next;
};

vector<Node*> listOfDepths(Node* root) {
  vector<LinkedListNode*> listOfDepths;

  listOfDepths.push_back(LinkedListNode(root));
  int curLayer = 0;
  while(listOfDepths[curLayer] !== nullptr) {
    LinkedListNode* temp = listOfDepths[curLayer];
    LinkedListNode* newLayer = new LinkedListNode();
    listOfDepths.push_back(newLayer);
    while(temp) {
      if(temp->node->left) {
        newLayer->next = LinkedListNode(temp->node->left);
        newLayer = newLayer->next;
      }
      if(temp->node->right) {
        newLayer->next = LinkedListNode(temp->node->right);
        newLayer = newLayer->next;
      }
      temp = temp->next;
    }
    curLayer++;
    temp = listOfDepths[curLayer];
    listOfDepths[curLayer] = temp->next;
    delete temp;
  }
  listOfDepths.erase(curLayer); //last layer will be []
}
