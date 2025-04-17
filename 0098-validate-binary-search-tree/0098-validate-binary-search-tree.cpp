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
    bool dfs(TreeNode* node, TreeNode* low, TreeNode* high){
        if(node == NULL) return true;
        if((low != NULL && node->val <= low->val) || (high != NULL && node->val >= high->val)) return false;
        
        bool left = dfs(node->left, low, node);
        bool right = dfs(node->right, node, high);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, NULL, NULL);
    }
};