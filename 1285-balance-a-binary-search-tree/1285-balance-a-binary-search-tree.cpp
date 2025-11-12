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
    void inorderTraversal(TreeNode* root, vector<int>& inorder){
        if(!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    TreeNode* buildTree(vector<int>& inorder, int left, int right){
        if(left > right) return NULL;
        int middle = left + (right-left)/2;
        TreeNode* node = new TreeNode(inorder[middle]);
        node->left = buildTree(inorder, left, middle-1);
        node->right = buildTree(inorder, middle+1, right);

        return node;
    }
    //TC: O(N+N), SC: O(N+N)
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        //TC: O(N), SC: O(N) stack space
        inorderTraversal(root, inorder);
        //TC: O(N), SC:O(N)
        return buildTree(inorder, 0, inorder.size()-1);
    }
};