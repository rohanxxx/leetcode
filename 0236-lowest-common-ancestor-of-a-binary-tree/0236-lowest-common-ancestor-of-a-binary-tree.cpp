/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 root = [3,5,1,6,2,0,8,null,null,7,4]
                                3
                            5       1
                        6       2 0     8
                              7  4
p = 5, q = 1


if(left && right) return curNode;
if(root == p || root == q) return root;
return NULL;

root = [3,5,1,6,2,0,8,null,null,7,4]
                            3
                        5       1
                    6     2   0   8
                        7   4
p = 5, q = 4

 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        TreeNode* leftTree = dfs(root->left, p, q);
        TreeNode* rightTree = dfs(root->right, p, q);
        if((p != NULL && root->val == p->val) || (q != NULL && root->val == q->val)){
            return root;
        }
        if(leftTree && rightTree) {
            return root;
        }
        if(leftTree) return leftTree;
        if(rightTree) return rightTree;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};