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
    
    bool inorderTraversal(TreeNode* root, long int& rootVal){
        if(root == NULL)
            return true;
        
        if(!inorderTraversal(root->left, rootVal))
            return false;
        
        if(rootVal >= root->val)
            return false;
        
        rootVal = root->val;
        
        if(!inorderTraversal(root->right, rootVal))
            return false;
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        long int rootVal = LONG_MIN;
        return inorderTraversal(root, rootVal);
    }
};