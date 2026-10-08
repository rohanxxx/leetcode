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
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL){
            return NULL;
        }

        TreeNode* left = dfs(node->left, p, q);
        TreeNode* right = dfs(node->right, p, q);

        if((left && right)||(node == p || node == q)){
            return node;
        }
        if(left){
            return left;
        }
    
        return right;
    }
    void dfs2(TreeNode* node, TreeNode* p, TreeNode* q, bool& boolp, bool& boolq){
        if(node == NULL){
            return;
        }
        if(node == p){
            boolp = true;
        }
        if(node == q){
            boolq = true;
        }
        dfs2(node->left, p, q, boolp, boolq);
        dfs2(node->right, p, q, boolp, boolq);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool boolp = false;
        bool boolq = false;
        dfs2(root, p, q, boolp, boolq);
        if(boolp == false || boolq == false){
            return NULL;
        }
        return dfs(root, p, q);
    }
};