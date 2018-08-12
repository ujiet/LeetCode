struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0) return NULL;
    
    /* create root */
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->left = root->right = NULL;
    root->val = preorder[0];
    
    /* recusive */
    int leftSize = 0, rightSize; 
    while (inorder[leftSize] != preorder[0]) 
        leftSize++;
    rightSize = preorderSize - leftSize - 1;
    
    root->left = buildTree(preorder + 1, leftSize, inorder, leftSize);
    root->right = buildTree(preorder + leftSize + 1, rightSize, inorder + leftSize + 1, rightSize);

    return root;
}
