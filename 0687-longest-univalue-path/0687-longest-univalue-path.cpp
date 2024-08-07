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
    int maxCount = 0;
    int dfs(TreeNode* parent, TreeNode* child){
        if(child == NULL) return 0;
        int left = dfs(child, child->left);
        int right = dfs(child, child->right);

        int count = 0;

        maxCount = max(maxCount, left+right);
        if(parent && parent->val == child->val) return max(left, right) + 1;
        
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(NULL, root);
        return maxCount;
    }
};