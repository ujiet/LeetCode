int sumOfLeftLeaves(struct TreeNode* root) {
    int sum = 0;
    
    if (root == NULL) 
        return sum;
    
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) 
        sum += root->left->val;
    
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    
    return sum;
}
