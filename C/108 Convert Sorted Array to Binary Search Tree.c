struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0)
        return NULL;
    
    int mid = numsSize / 2;
    struct TreeNode *head = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    head->val = nums[mid];
    head->left = sortedArrayToBST(nums, mid);
    head->right = sortedArrayToBST(nums + mid + 1, numsSize - mid -1);
    
    return head;
}
