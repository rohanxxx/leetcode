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
    int dfs(TreeNode* node, string& ans){
        if(node == NULL){
            return 0;
        }
        
        ans += to_string(node->val);
        
        ans.push_back('(');
        int left = dfs(node->left, ans);
        ans.push_back(')');

        ans.push_back('(');
        int right = dfs(node->right, ans);
        ans.push_back(')');

        if(right == 0 && left == 0){
            for(int i = 0; i < 4; i++){
                ans.pop_back();
            }
        }

        if(left == 1 && right == 0){
            for(int i = 0; i < 2; i++){
                ans.pop_back();
            }
        }
        return 1;
    }
    string tree2str(TreeNode* root) {
        string ans = "";
        dfs(root, ans);
        return ans;
    }
};