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
    TreeNode* dfs(TreeNode* o, TreeNode* c, TreeNode* t){
        if(o == NULL) return NULL;
        if(o->val == t->val && c->val == t->val){
            return c;
        }
        TreeNode* leftNode = dfs(o->left, c->left, t);
        TreeNode* rightNode = dfs(o->right, c->right, t);

        if(leftNode) return leftNode;
        return rightNode;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(original, cloned, target);
    }
};