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
    void dfs(TreeNode* root, vector<int>& ans){
        if(!root) return;
        
        int count = 0;
        if(root->left) count++;
        if(root->right) count++;

        if(count == 1){
            if(root->left) ans.push_back(root->left->val);
            if(root->right) ans.push_back(root->right->val);
        }

        dfs(root->left, ans);
        dfs(root->right, ans);
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};