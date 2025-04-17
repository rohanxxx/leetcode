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
    void bst(TreeNode* node, int& val){
        if(val < node->val){
            if(node->left){
                bst(node->left, val);
            }
            else{
                node->left = new TreeNode(val);
            }
        }
        else if (val > node->val){
            if(node->right){
                bst(node->right, val);
            }
            else{
                node->right = new TreeNode(val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return root = new TreeNode(val);
        bst(root, val);
        return root;
    }
};