/*
Partition a linked list around a value x such that all y < x are before y > x
*/

Node* partition(Node* head, int x) {
  Node* newHead = head;
  Node* newTail = head;

  while( head != nullptr ) {
    Node* temp = head->next;
    if( head->val < x ) {
      head->next = newHead;
      newHead = head;
    } else {
      newTail->next = head;
      newTail = head;
    }
    head = temp;
  }

  return newHead;
}

