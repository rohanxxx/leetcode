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
    int totalCount = 0;
    vector<int> dfs(TreeNode* root){
        if(!root) return {0,0};
        
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        
        int subTreeSum = root->val + left[0] + right[0];
        int nodeCount = 1 + left[1] + right[1];
        
        if(root->val == (subTreeSum/nodeCount)) totalCount++;
        
        return {subTreeSum, nodeCount};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return totalCount;
    }
};