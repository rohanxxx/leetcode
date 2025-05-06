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
    int getHeight(TreeNode* root, vector<vector<int>>& ans){
        if(root == NULL) return -1;
        
        int leftHeight = getHeight(root->left, ans);
        int rightHeight = getHeight(root->right, ans);
        int curHeight = max(leftHeight, rightHeight) + 1;

        if(curHeight == ans.size()){
            ans.push_back({});
        }

        ans[curHeight].push_back(root->val);
        
        return curHeight;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        getHeight(root, ans);
        return ans;
    }
};