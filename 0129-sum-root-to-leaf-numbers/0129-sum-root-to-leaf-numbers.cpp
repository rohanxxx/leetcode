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
                                    4 
                                9       0
                            5   1       
    4 + 49 + 40 + 495 + 491 = 1026

 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int allSum = 0;
        //pair<Node, curPathSum>
        queue<pair<TreeNode*, long long>> q;
        q.push({root, root->val});

        while(!q.empty()){
            TreeNode* curNode = q.front().first;
            int curPathSum = q.front().second;
            q.pop();

            if(curNode->left == NULL && curNode->right == NULL){
                allSum += curPathSum;
                continue;
            }

            if(curNode->left){
                q.push({curNode->left, (long long)curNode->left->val + (long long)(curPathSum*(long long)10)});
            }

            if(curNode->right){
                q.push({curNode->right, (long long)curNode->right->val + (long long)(curPathSum*(long long)10)});
            }
        }

        return allSum;
    }
};