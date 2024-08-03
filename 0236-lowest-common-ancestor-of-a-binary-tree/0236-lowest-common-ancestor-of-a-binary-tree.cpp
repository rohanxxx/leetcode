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
    TreeNode* LCA;
    bool dfs(TreeNode* currentNode, TreeNode* p, TreeNode* q){
        if(!currentNode) return NULL;
        
        int left = 0, right = 0, mid = 0;
        if(dfs(currentNode->left, p, q)) left = 1;
        if(dfs(currentNode->right, p, q)) right = 1;
        if(currentNode == p || currentNode == q) mid = 1;
        
        if(left+right+mid >= 2) LCA = currentNode;
        
        return left+right+mid;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return LCA;
    }
};