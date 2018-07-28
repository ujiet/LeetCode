/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * To find ount the LCA in a BST, we can imagine there are 2 roads in the BST, roadP and roadQ.
 * Each one is the traversing path when searching for the value of p or q. We know that the search path for   
 * each node is unique, and since the LCA is the ancestor of both nodes, so LCA is exist in the both roads.   
 * So what we need to do is find the split point of the path, and it will be the anwser.
 */
 
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root && p && q) {
        if ((p->val > root->val) && (q->val > root->val)) {
            root = root->right;
        } else if ((p->val < root->val) && (q->val < root->val)) {
            root = root->left;
        } else {
            return root;
        }
    }
    
    return root;
}
