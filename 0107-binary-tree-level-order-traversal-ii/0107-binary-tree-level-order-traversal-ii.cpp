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
    vector<vector<int>> levels;
    void helper(TreeNode* node, int level) {
        // start the current level
        if (levels.size() == level) levels.push_back(vector<int>());
        // append the current node value
        levels[level].push_back(node->val);
        // process child nodes for the next level
        if (node->left != NULL) helper(node->left, level + 1);
        if (node->right != NULL) helper(node->right, level + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) return levels;
        helper(root, 0);
        reverse(levels.begin(), levels.end());
        return levels;
    }
};