bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) return false;
    
    sum -= root->val;
    if (!sum && !root->left && !root->right) return true;
    
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
