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
    TreeNode* prev;
    void dfs(TreeNode* node){
        if(!node) return;
        dfs(node->right);
        dfs(node->left);
        node->right = prev;
        node->left = NULL;
        prev = node;
    }
    void flatten(TreeNode* root) {
        prev = NULL;
        dfs(root);
    }
};