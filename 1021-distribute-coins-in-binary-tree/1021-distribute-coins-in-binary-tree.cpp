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
    int moves;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int leftCoin = dfs(root->left);
        int rightCoin = dfs(root->right);
        moves += (abs(leftCoin) + abs(rightCoin));
        return (root->val-1)+leftCoin+rightCoin;
    }
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};