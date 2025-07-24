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
    void dfs(TreeNode* root, set<int>& set){
        if(!root) return;
        set.insert(root->val);
        
        dfs(root->left, set);
        dfs(root->right, set);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> set;
        dfs(root, set);
        
        int i = 0; 
        for(auto& it: set){
            i++;
            if(i == 2) return it;
        }

        return -1;
    }
};