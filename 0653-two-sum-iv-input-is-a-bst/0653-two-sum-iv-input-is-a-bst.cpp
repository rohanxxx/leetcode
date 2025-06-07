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
    void dfs(TreeNode* root, int k, bool& exists, unordered_map<int, int>& map){
        if(root == NULL) return;
        
        if(map[k-root->val] == 1) exists = true;
        if(exists == true) return;

        map[root->val] = 1;
        dfs(root->left, k, exists, map);
        dfs(root->right, k, exists, map);
    }
    bool findTarget(TreeNode* root, int k) {
        bool exists = false;
        unordered_map<int, int> map;
        dfs(root, k, exists, map);
        return exists;
    }
};