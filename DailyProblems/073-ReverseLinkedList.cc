/* 73. Google
Given the head of a singly linked list, reverse it in-place.
*/

void reverseLinkedList( Node* head ) {
  Node* newHead = nullptr;

  while( head ) {
    Node* temp = head;
    head = head->next;
    temp->next = newHead;
    newHead = temp;
  }

  return newHead;
}
