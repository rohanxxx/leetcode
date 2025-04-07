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
    int dfs(TreeNode* node){
        if(!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        return node->val + left + right;
    }
    bool check(TreeNode* node){
        if(node->left == NULL && node->right == NULL) return true;
        int left = dfs(node->left);
        int right = dfs(node->right);
        return node->val == left + right && check(node->left) && check(node->right);
    }
    bool checkTree(TreeNode* root) {
        return check(root);
    }
};