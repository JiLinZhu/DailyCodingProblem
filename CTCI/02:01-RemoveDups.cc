/*
Remove dups from an unsorted linked list
*/

void removeDups( Node* head ) {
  unordered_set<char> x;

  x.insert(head->val);
  Node* prev = null;

  while( head != nullptr ) {
    if( x.find(head->val) != x.end() ) {
      prev->next = head->next;
      delete head;
      head = prev->next;
    } else {
      x.insert(head->val);
      prev = head;
      head = head->next;
    }
  }
}
