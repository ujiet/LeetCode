int balanceFactor(struct TreeNode* root) {
    if (root == NULL) return 0;
    int hl, hr, dep;
    
    hl = balanceFactor(root->left);
    if (hl == -1) return -1;
    hr = balanceFactor(root->right);
    if (hr == -1) return -1;
    
    if (hl - hr < -1 || hl - hr > 1) 
        return -1;
    if (hl > hr)
        dep = hl;
    else
        dep = hr;
    
    return ++dep;
    
}

bool isBalanced(struct TreeNode* root) {
    return balanceFactor(root) != -1;
}
