/* 78. Google
Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.
*/

ListNode* merge( ListNode* a, ListNode* b ) {
  ListNode* newHead;
  if(a == NULL && b == NULL) return NULL;
  else if ( a && b == NULL ) {
    newHead = a;
    a = a->next;
  } else if ( a == NULL && b ) {
    newHead = b;
    b = b->next;
  } else if( a->val < b->val ) {
    newHead = a;
    a = a->next;
  } else {
    newHead = b;
    b = b->next;
  }

  ListNode* result = newHead;

  while(a && b) {
    if( a->val < b->val ) {
      newHead->next = a;
      a = a->next;
    } else {
      newHead->next = b;
      b = b->next;
    }
    newHead = newHead->next;
  }

  if(a) {
    newHead->next = a;
  } else {
    newHead->next = b;
  }
  return result;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  int interval = 1;
  int size = lists.size();
  if(size == 0) return nullptr;
  while( interval < size ) {
    for( int i = 0; i < size; i += 2*interval ) {
      if(i+interval >= size) break;
      lists[i] = merge(lists[i], lists[i+interval]);
    }
    interval *= 2;
  }
  return lists[0];
}
