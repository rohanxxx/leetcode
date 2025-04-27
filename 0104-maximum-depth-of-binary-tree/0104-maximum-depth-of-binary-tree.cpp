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
    int depth;
    void dfs(TreeNode* root, int curDepth){
        if(root == NULL){
            depth = max(depth, curDepth);
            return;
        }
        curDepth++;
        //depth = max(depth, curDepth);
        dfs(root->left, curDepth);
        dfs(root->right,curDepth);
    }
    int maxDepth(TreeNode* root) {
        int curDepth;
        depth = curDepth = 0;
        dfs(root, curDepth);
        return depth;
    }
};