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
    Input: root = [1,2,3]
    Output: 1
                            
                            1
                        2       3
                    4.  5       6   7
 */
class Solution {
public:
    //dfs
    //TC: O(N)
    //SC: O(Tree Height) Tree Height belongs to N
    int dfs(TreeNode* root, int& differenceSum){
        if(root == NULL){
            return 0;
        }

        int leftSum = dfs(root->left, differenceSum);
        int rightSum = dfs(root->right, differenceSum);

        differenceSum += abs(leftSum-rightSum);

        return root->val+leftSum+rightSum;
    }
    int findTilt(TreeNode* root) {
        int differenceSum = 0;
        dfs(root, differenceSum);
        return differenceSum;
    }
};