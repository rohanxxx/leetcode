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
class Solution {
    public:
    TreeNode* functions(int left, int right, vector<int>& nums) {
        if(left > right) {
            return NULL;
        }

        int index = max_element (nums.begin()+left, nums.begin()+right+1) - nums.begin();

        TreeNode* node = new TreeNode(nums[index]);
        node->left = functions(left,index-1,nums);
        node->right = functions(index+1,right,nums);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return functions(0,nums.size()-1,nums);
    }
};