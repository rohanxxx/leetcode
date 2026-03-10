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
    int maxSum;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int leftSum = max(dfs(root->left), 0);
        int rightSum = max(dfs(root->right), 0);

        maxSum = max(maxSum, root->val + leftSum + rightSum);

        return root->val+max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
};