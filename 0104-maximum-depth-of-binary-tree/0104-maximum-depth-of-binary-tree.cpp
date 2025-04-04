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
    int dfs(TreeNode* node){
        if(!node) return 0;
        int left_count = dfs(node->left);
        int right_count = dfs(node->right);
        return 1 + max(left_count, right_count);
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};