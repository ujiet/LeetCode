int minDepth(struct TreeNode* root) {
    int hl, hr;
    
    if (root == NULL) return 0;
    hr = minDepth(root->right);
    hl = minDepth(root->left);
    
    return ((hl < hr) && hl) || !hr ?  1 + hl : 1 + hr;
    
}
