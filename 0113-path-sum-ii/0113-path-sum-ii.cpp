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
                                5
                            4       8
                        11          13  4
                    7   2               5   1
                output: {{5,4,11,2},{5,8,4,1}}
 */
class Solution {
    //implement my dfs
    //inside the dfs check if root null
    //check if it is leaf node
    //if leaf then check with the targetsum if matches push it to the ans vector
    //then we would call left and right child passing along with the root value in temp vector as parameter of dfs
    void dfs(TreeNode* root, int curSum, int& targetSum, vector<int> temp, vector<vector<int>>& ans){
        if(root == NULL){
            return;
        }
        temp.push_back(root->val);
        //check if it's a leaf node
        if(root->left == NULL && root->right == NULL){
            if(curSum+root->val == targetSum){
                ans.push_back(temp);
            }
            return;
        }
        dfs(root->left, curSum + root->val, targetSum, temp, ans);
        dfs(root->right, curSum + root->val, targetSum, temp, ans);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //first do edge case check if root is null
        if(root == NULL) {
            return vector<vector<int>> ();
        }
        //declare our variable like vector<vector<int>> ans
        vector<vector<int>> ans;
        //call the dfs(root, temp, targetSum);
        dfs(root, 0, targetSum, vector<int>(), ans);
        return ans;
    }
};