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
    int ans;
    void dfs(TreeNode* root, int& k, int& count){
        if(root == NULL) return;
        dfs(root->left, k, count);
        if(++count == k){
            ans = root->val;
        }
        dfs(root->right, k, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        ans = INT_MIN;
        int count = 0;
        dfs(root, k, count);
        return ans;
    }
};