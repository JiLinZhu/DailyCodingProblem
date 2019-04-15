/*
Determine if two linked lists intersect.
*/

bool intersection(Node* a, Node* b) {
  int lenA = getLen(a);
  int lenB = getLen(b);

  if( lenB < lenA ) {
    int diff = lenA - lenB;
    while ( diff-- > 0 ) {
      a = a->next;
    }
  } else {
    int diff = lenB - lenA;
    while( diff > 0 ) {
      b = b->next;
    }
  }

  while ( a && b ) {
    if( a == b ) return true;
    a = a->next;
    b = b->next;
  }
  return false;
}

// Can also check if tail are the same immediately
