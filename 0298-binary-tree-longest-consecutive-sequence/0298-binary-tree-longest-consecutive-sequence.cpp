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
    int maxSeq = 0;
    void traverse(TreeNode* cur, int len, TreeNode* prev){
        if(prev && cur->val == prev->val+1){
            len++;
        }
        else{
            len = 1;
        }

        maxSeq = max(maxSeq, len);
        
        if(cur->left) traverse(cur->left, len, cur);
        if(cur->right) traverse(cur->right, len, cur);

        return;
    }
    int longestConsecutive(TreeNode* root) {
        if(root) traverse(root, 0, NULL);
        return maxSeq;
    }
};