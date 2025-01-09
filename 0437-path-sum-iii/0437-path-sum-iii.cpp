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
    int count = 0;
    unordered_map<long long, int> mp;
    void traverse(TreeNode* node, long long currentSum, int& targetSum){
        if(!node) return;
        
        currentSum += node->val;

        if(currentSum == targetSum) count++;
        if(mp[currentSum - targetSum]) count += mp[currentSum - targetSum];

        mp[currentSum]++;

        traverse(node->left, currentSum, targetSum);
        traverse(node->right, currentSum, targetSum);

        mp[currentSum]--;
        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
        traverse(root, (long long)0, targetSum);
        return count;
    }
};