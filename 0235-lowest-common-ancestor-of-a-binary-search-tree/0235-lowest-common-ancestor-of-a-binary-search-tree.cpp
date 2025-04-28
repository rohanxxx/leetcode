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
    /*
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        if(root->val > p->val && root->val > q->val) then go to left
        else if root->val < p->val && root->val < q->val then go to right

        return root;
    */
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root->val == p->val || root->val == q->val) return root;
        if(root->val > p->val && root->val > q->val){
            return dfs(root->left, p, q);
        }
        if(root->val < p->val && root->val < q->val){
            return dfs(root->right, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};