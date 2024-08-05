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
    TreeNode* dfs(TreeNode* currentNode, TreeNode* p, TreeNode* q){
        if(!currentNode) return NULL;

        TreeNode* leftTree = dfs(currentNode->left, p, q);
        TreeNode* rightTree = dfs(currentNode->right, p, q);

        if((leftTree && rightTree) || (currentNode == p || currentNode == q)) return currentNode;
        
        if(leftTree == NULL) return rightTree;
        return leftTree;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*if(!root) return NULL;
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;*/
        return dfs(root, p, q);
    }
};