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
    int result = 0;
    int dfs(TreeNode* node, int prevVal){
        if(!node) return 0;
        int left = dfs(node->left, node->val);
        int right = dfs(node->right, node->val);

        result = max(result, left+right);
        if(node->val == prevVal) return max(left, right)+1;
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root, -1);
        return result;
    }
};