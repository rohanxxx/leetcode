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
    bool dfs(TreeNode* root, int k, unordered_map<int, int>& map){
        if(root == NULL) return false;
        
        if(map[k-root->val] == 1) return true;

        map[root->val] = 1;
        return dfs(root->left, k, map) || dfs(root->right, k, map);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> map;
        return dfs(root, k, map);
    }
};