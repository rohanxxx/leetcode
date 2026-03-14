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
    int maxCount = 0;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int leftCount = dfs(root->left);
        int rightCount = dfs(root->right);

        maxCount = max(maxCount, leftCount+rightCount);
        return 1+(int)max(leftCount, rightCount);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxCount;
    }
};