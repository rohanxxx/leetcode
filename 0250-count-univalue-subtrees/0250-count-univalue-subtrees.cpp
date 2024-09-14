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
    int count = 0;
    bool dfs(TreeNode* node){
        if(node == NULL) return true;
        bool isLeftUniValue = dfs(node->left);
        bool isRightUniValue = dfs(node->right);

        if(isLeftUniValue && isRightUniValue){
            if(node->left && node->left->val != node->val) return false;
            if(node->right && node->right->val != node->val) return false;
            count++;
            return true;
        }

        return false;
    }

    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return count;
    }
};