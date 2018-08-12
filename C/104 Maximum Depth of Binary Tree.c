int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int hl, hr, dep;
    
    hl = maxDepth(root->left);
    hr = maxDepth(root->right);
    if (hl > hr) 
        dep = hl;
    else
        dep = hr;
    
    return ++dep;
}
