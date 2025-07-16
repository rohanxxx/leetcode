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

 /*
    Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
    Output: 18

                                6
                            /       \
                           7         8
                        /   \       / \
                       2     7     1   3
                    /       / \         \
                  9        1.  4         5

 */
class Solution {
public:
    int sum;
    void getSum(TreeNode* node){
        if(node){
            if(node->left){
                sum += node->left->val;
            }
            if(node->right){
                sum += node->right->val;
            }
        }
    }
    void dfs(TreeNode* root){
        if(root == NULL) return;
        if(root->val % 2 == 0){
            getSum(root->left);
            getSum(root->right);
        }
        dfs(root->left);
        dfs(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        sum = 0;
        dfs(root);
        return sum;
    }
};