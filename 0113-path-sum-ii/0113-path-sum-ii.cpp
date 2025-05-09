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
    root = [5,4,8,11,null,13,4,7,2,null,null,5,1]
                                            5
                                        4       8
                                    11  N       13      4
                                7   2           N  n    5 1
    
    targetSum = 22;
    {5,4,11,2}, {5,8,4,5}
 */
class Solution {
public:
    void dfs(TreeNode* root, int prev_sum, vector<int> temp, int& targetSum, vector<vector<int>>& ans){
        if(root == NULL) return;
        int curSum = prev_sum + root->val;
        temp.push_back(root->val);
        //checks if it is a leaf node or not
        if(root->left == NULL && root->right == NULL){
            if(curSum == targetSum){
                ans.push_back(temp);
            }
            return;
        }

        dfs(root->left, curSum, temp, targetSum, ans);
        dfs(root->right, curSum, temp, targetSum, ans);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //edge case
        if(root == NULL){
            return vector<vector<int>>();
        }
        vector<vector<int>> ans;
        dfs(root, 0, vector<int>(), targetSum, ans);
        return ans;
    }
};