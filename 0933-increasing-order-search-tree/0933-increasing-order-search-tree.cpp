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
    TreeNode* curr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        root->left = nullptr;       // remove left child
        curr->right = root;         // attach to the right of current
        curr = root;                // move current forward

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1); // dummy node
        curr = dummy;
        inorder(root);
        return dummy->right;
    }
};