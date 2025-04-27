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
    int dfs(TreeNode* root, int& maxDiameter){
        if(root == NULL) return 0;
        int leftNodeCount = dfs(root->left, maxDiameter);
        int rightNodeCount = dfs(root->right, maxDiameter);
        
        int curDiameter = leftNodeCount+rightNodeCount;
        
        maxDiameter = max(maxDiameter, curDiameter);
        
        return 1+ max(leftNodeCount, rightNodeCount);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        dfs(root, maxDiameter);
        return maxDiameter;
    }
};