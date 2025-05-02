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
    int maxSum = INT_MIN;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int leftPathSum = max(dfs(root->left), 0);
        int rigthPathSum = max(dfs(root->right), 0);
        maxSum = max(maxSum, root->val + leftPathSum + rigthPathSum);
        return root->val + max(leftPathSum, rigthPathSum);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};