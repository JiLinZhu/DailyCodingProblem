/*
Given two linked list storing a number's digits in reverse order, sum the numbers into 1 list.
*/

Node* sumLists(Node* a, Node* b, int carry) {
  if( a == nullptr && b == nullptr && carry == 0 ) return nullptr;

  if( !a && b ) {
    a = b;
    b = nullptr;
  }

  if(!a && !b) {
    return new Node(carry);
  }

  a->val = a->val + b ? b->val : 0 + carry;
  carry = a->val / 10;
  a->val %= 10;

  Node* temp = b->next;
  delete b;


  a->next = sumLists(a->next, temp, carry)

  return a;
}
