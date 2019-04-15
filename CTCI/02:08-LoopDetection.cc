/*
Given a circular linked list, return the start of the loop.
*/

Node* loopDetection(Node* head) {
  Node* slow = head;
  Node* fast = head;

  while( slow != fast ) { // note the guaranteed loop
    slow = slow->next;
    fast = fast->next->next;
  }

  while( head != slow ) {
    head = head->next;
    slow = slow->next;
  }

  return head;
}
