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
    pair<int, int> dfs(TreeNode* node){
        if(node == NULL){
            return {0,0};
        }

        pair<int, int> leftRet = dfs(node->left);
        pair<int, int> rightRet = dfs(node->right);

        pair<int, int> ret = {leftRet.first+rightRet.first, max({node->val, leftRet.second, rightRet.second})};
        if(node->val >= leftRet.second && node->val >= rightRet.second){
            ret.first += 1;
        }

        return ret;
    }
    int countDominantNodes(TreeNode* root) {
        pair<int, int> ret = dfs(root);
        return ret.first;
    }
};