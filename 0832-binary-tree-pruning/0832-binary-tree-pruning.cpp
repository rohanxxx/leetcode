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
    TreeNode* dfs(TreeNode* root){
        if(root == NULL) return root;
        TreeNode* rootLeft = dfs(root->left);
        TreeNode* rootRight = dfs(root->right);

        if(rootLeft == NULL && rootRight == NULL && root->val == 0){
            return NULL;
        }

        TreeNode* newRoot = root;
        newRoot->left = rootLeft;
        newRoot->right = rootRight;
        return newRoot;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }
};