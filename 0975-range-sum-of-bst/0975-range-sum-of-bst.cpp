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
    void dfs(TreeNode* root, int low, int high, int& rangeSum){
        if(root == NULL) return;
        if(low <= root->val && root->val <= high){
            // cout << "root->val: " << root->val << endl;
            rangeSum += root->val;
        }
        dfs(root->left, low, high, rangeSum);
        dfs(root->right, low, high, rangeSum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int rangeSum = 0;
        dfs(root, low, high, rangeSum);
        return rangeSum;
    }
};