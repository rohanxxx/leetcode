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
    pair<TreeNode*, int> dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL){
            return {NULL, 0};
        }

        pair<TreeNode*, int> leftTree = dfs(node->left, p, q);
        pair<TreeNode*, int> rightTree = dfs(node->right, p, q);

        int count = leftTree.second+rightTree.second;
        if((leftTree.first && rightTree.first)){
            return {node, count};
        }
        if(node == p || node == q){
            return {node, count+1};
        }
        if(leftTree.first){
            return {leftTree.first, leftTree.second};
        }
    
        return {rightTree.first, rightTree.second};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        pair<TreeNode*, int> ret = dfs(root, p, q);

        if(ret.second == 2){
            return ret.first;
        }
        return NULL;
    }
};