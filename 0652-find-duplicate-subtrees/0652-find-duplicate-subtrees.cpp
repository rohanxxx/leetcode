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
    string dfs(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& ans){
        if(root == NULL) return "*";
        string leftStr = dfs(root->left, mp, ans);
        string rightStr = dfs(root->right, mp, ans);
        if(leftStr == "*") leftStr = "(";
        if(rightStr == "*") rightStr = ")";
        string curStr = leftStr + to_string(root->val) + rightStr;
        //cout << "curStr: " << curStr << endl;
        mp[curStr]++;
        
        if(mp[curStr] == 2){
            ans.push_back(root);
        }
        
        return curStr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> mp;
        dfs(root, mp, ans);
        return ans;
    }
};