/*
Check if a linked list is a palindrome
*/

bool palindrome(ListNode** head, ListNode* tail) {
  if(!tail) return true;
  if ( palindrome(head, tail->next ) ){
    if( (*head)->val != tail->val ) return false;
    *head = (*head)->next;
    return true;
  }
  return false;
}
