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
    long long dfs(TreeNode* node, int& count){
        if(node == NULL){
            return 0;
        }

        long long leftSum = dfs(node->left, count);
        long long rightSum = dfs(node->right, count);

        if((long long)node->val == (long long)leftSum+rightSum){
            count++;
        }
        return (long long)node->val+leftSum+rightSum;
    }
    int equalToDescendants(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
};