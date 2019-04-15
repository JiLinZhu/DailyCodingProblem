/*
Return kth last node in a linked list
*/

Node* returnKthToLast( Node* head, int k ) {
  Node* lead = head;
  for( int i = 0 ; i < k; i++ ) {
    if( lead == nullptr ) return nullptr;
    lead = lead->next;
  }

  while( lead ) {
    head = head->next;
    lead = lead->next;
  }

  return head;
}
