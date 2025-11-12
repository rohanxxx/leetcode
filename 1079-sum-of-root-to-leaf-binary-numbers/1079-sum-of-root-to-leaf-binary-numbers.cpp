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
private:
    int rootToLeafSum = 0;
public:
    void preorderTraversal(TreeNode* root, int cur){
        if(root == NULL) {
            return;
        }
        cur = ((cur << 1) | root->val);
        if(root->left == NULL && root->right == NULL){
            rootToLeafSum += cur;
        }
        preorderTraversal(root->left, cur);
        preorderTraversal(root->right, cur);
    }
    int sumRootToLeaf(TreeNode* root) {
        preorderTraversal(root, 0);
        return rootToLeafSum;
    }
};