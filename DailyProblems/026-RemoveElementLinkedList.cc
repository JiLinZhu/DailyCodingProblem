/* 26. Google
Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.
*/

void removeKthElement( Node* root, int k ) {
	Node* lead = root;
	for( int i = 0; i < k; i++ ) {
		lead = lead->next;
	}

	if( lead == NULL ) {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    lead = lead->next;
        

	while( lead != nullptr ) {
		lead = lead->next;
		root = root->next;
	}
	// root is now one before the node to be deleted

	lead = root->next; 
	root->next = lead ? lead->next : nullptr; // in case lead == null
	delete lead;
}