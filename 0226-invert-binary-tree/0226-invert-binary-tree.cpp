/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root){
        if(root == NULL) return NULL;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = dfs(right);
        root->right = dfs(left);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }
};