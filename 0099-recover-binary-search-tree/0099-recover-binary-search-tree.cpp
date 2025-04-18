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
    void dfs(TreeNode* root, vector<int>& inorder){
        if(root == NULL) return;
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
        return;
    }
    void dfs(TreeNode* root, vector<int>& inorder, int& index){
        if(root == NULL) return;
        dfs(root->left, inorder, index);
        if(root->val != inorder[index]){
            root->val = inorder[index];
        }
        index++;
        dfs(root->right, inorder, index);
    }
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        dfs(root, inorder);
        sort(inorder.begin(), inorder.end());
        int index = 0;
        dfs(root, inorder, index);
    }
};