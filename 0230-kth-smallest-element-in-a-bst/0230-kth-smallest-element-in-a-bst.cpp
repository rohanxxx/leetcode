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
    int kthElement;
    void bst(TreeNode* node, int& k, int& count){
        if(!node) return;
        bst(node->left, k, count);
        if(++count == k){
            kthElement = node->val;
            return;
        }
        bst(node->right, k, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        kthElement = INT_MAX;
        bst(root, k, count);
        return kthElement;
    }
};