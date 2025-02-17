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
    void dfs(TreeNode* root, vector<string>& ans, string str){
        str += to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(str);
            return;
        }
        str += "->";
        if(root->left){
            dfs(root->left, ans, str);
        }
        if(root->right){
            dfs(root->right, ans, str);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
            return {};
        }
        
        string str = "";
        str += to_string(root->val);
        if(!root->left && !root->right){
            return {str};
        }
        vector<string> ans;
        str += "->";
        if(root->left){
            dfs(root->left, ans, str);
        }
        if(root->right){
            dfs(root->right, ans, str);
        }

        return ans;
    }
};