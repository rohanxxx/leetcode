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
    int goodNodesCount = 0;
    void dfs(TreeNode* root, int maxSofar){
        if(root->val >= maxSofar) goodNodesCount++;
        if(root->left) dfs(root->left, max(maxSofar, root->val));
        if(root->right) dfs(root->right, max(maxSofar, root->val));
    }
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return goodNodesCount;
    }
};