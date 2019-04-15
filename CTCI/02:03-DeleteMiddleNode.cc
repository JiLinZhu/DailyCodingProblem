/*
Delete a node in the linked list. It will not be the first or last.
*/

void deleteMiddleNode( Node* someNode ) {
  someNode->val = someNode->next->val;
  Node* temp = someNode->next;
  someNode->next = someNode->next->next;
  delete temp;
}
