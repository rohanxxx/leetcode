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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        dfs(root, inorder);
        if(inorder.size() >= k){ 
            return inorder[k-1];
        }
        return -1;
    }
};