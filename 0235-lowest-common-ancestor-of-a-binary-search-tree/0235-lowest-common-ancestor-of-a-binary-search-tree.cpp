/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* bst(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL)  return NULL;
        if(node->val < p->val && node->val < q->val){
            return bst(node->right, p, q);
        }
        if (node->val > p->val && node->val > q->val){
            return bst(node->left, p, q);
        }
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return bst(root, p, q);
    }
};