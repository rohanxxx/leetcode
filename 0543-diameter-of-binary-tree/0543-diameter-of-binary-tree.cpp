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
    int dfs(TreeNode* root, int& maxDepth){
        if(!root){
            return 0;
        }
        int leftCount = dfs(root->left, maxDepth);
        int rightCount = dfs(root->right, maxDepth);
        maxDepth = max(maxDepth, leftCount+rightCount);
        return 1 + (int)max(leftCount, rightCount);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDepth = 0;
        dfs(root, maxDepth);
        return maxDepth;
    }
};