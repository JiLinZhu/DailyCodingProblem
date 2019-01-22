/* 24. Google
Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:

is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.
You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.
*/

struct Node {
	Node* left;
	Node* right;
	Node* parent;
	bool locked;
	int numLockedDescendants;
}


bool is_locked( Node* root ) {
	return root->locked;
}

bool changeCountLocked( Node* root, int change ) {
	while( root ) {
		root->numLockedDescendants += change;
		root = root->parent;
	}
	return true;
}

bool lock( Node* root ) {
	if( root->locked ) return true;

	if( root->numLockedDescendants == 0 ) {
		root->locked = true;
		return changeCountLocked( root->parent, 1 );
	}

	while( root ) {
		if( root->locked ) return false;
		root = root->parent;
	}

	return true;
}

bool unlock( Node* root ) {
	if( !root->locked ) return true;

	if( root->numLockedDescendants == 0 ) {
		root->locked = false;
		return changeCountLocked( root->parent, -1);
	}

	while( root ) {
		if( root->locked ) return false;
		root = root->parent;
	}

	return true;
}