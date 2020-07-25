/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* pruneTree(struct TreeNode* root){
    if(root == NULL) return root;
    //DFS
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    return (root->left ==NULL && root->right == NULL && root->val == 0) ? NULL : root;
}