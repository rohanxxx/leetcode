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
    int maxval = 0;
        std::pair<int, int> longestPath(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        
        int inr = 1, dcr = 1;
        if (root->left != nullptr) {
            auto left = longestPath(root->left);
            if (root->val == root->left->val + 1) {
                dcr = left.second + 1;
            } else if (root->val == root->left->val - 1) {
                inr = left.first + 1;
            }
        }
        
        if (root->right != nullptr) {
            auto right = longestPath(root->right);
            if (root->val == root->right->val + 1) {
                dcr = std::max(dcr, right.second + 1);
            } else if (root->val == root->right->val - 1) {
                inr = std::max(inr, right.first + 1);
            }
        }
        
        maxval = std::max(maxval, dcr + inr - 1);
        return {inr, dcr};
    }

    int longestConsecutive(TreeNode* root) {
        longestPath(root);
        return maxval;
    }
};