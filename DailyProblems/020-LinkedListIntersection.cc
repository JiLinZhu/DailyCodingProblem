/* 20. Google
Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.
For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
In this example, assume nodes with the same value are the exact same node objects.
Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/

int getLen( ListNode* headA ) {
    int count = 0;
    while( headA ) {
        count++;
        headA = headA->next;
    }
    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int aLen = getLen( headA );
    int bLen = getLen( headB );
    
    if( aLen > bLen ) {
        for( int i = 0; i < aLen-bLen; i++ ) {
            headA = headA->next;
        }
    } else if ( bLen > aLen ) {
        for( int i = 0; i < bLen-aLen; i++ ) {
            headB = headB->next;
        }
    }
    
    while( headA ) {
        if( headA == headB ) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

// Note: This can be done by setting pointerA = headB to it reaches the end (this will negate the difference in length)
