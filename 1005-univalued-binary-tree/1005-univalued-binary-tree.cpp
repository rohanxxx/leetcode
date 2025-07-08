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
    bool dfs(TreeNode* root, int& firstVal){
        if(root == NULL) return true;
        if(root->val != firstVal) return false;
        bool leftCheck = dfs(root->left, firstVal);
        bool rightCheck = dfs(root->right, firstVal);
        return leftCheck == true && rightCheck == true;
    }
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        int firstVal = root->val;
        return dfs(root, firstVal);
    }
};