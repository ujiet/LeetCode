bool sym(struct TreeNode* l, struct TreeNode* r) {
    if (l == NULL && r == NULL) return true;
    if (l == NULL || r == NULL) return false;
    if (l->val != r->val) return false;
    if (!sym(l->left, r->right) || !sym(l->right, r->left)) return false;
    
    return true;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;  // null tree
    return sym(root->left, root->right);
}
