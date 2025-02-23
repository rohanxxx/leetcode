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
    vector<TreeNode*> pre;
    void dfs(TreeNode* cur){
        if(!cur) return;
        
        pre.push_back(cur);

        TreeNode* left = cur->left;
        TreeNode* right = cur->right;
        
        cur->left = NULL;
        cur->right = NULL;

        dfs(left);
        dfs(right);
    }
    
    void flatten(TreeNode* root) {
        dfs(root);
        TreeNode* temp = root;
        for(int i = 1; i < pre.size(); i++){
            temp->right = pre[i];
            temp = temp->right;
        }
    }
};