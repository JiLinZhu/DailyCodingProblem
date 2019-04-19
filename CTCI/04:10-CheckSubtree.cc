/*
Given two binary trees, check if T2 is a subtree of T1.
*/

bool checkMatch( TreeNode* s, TreeNode *t) {
    if( s == NULL  ) return t == NULL;
    if( t == NULL ) return s == NULL;
    return s->val != t->val ? false : checkMatch(s->right, t->right) && checkMatch(s->left, t->left);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if( t == NULL ) return true;
    if( s == NULL ) return false;
    if( s->val == t->val ) {
        bool match = checkMatch(s, t);
        if( match ) return true;
    }
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
