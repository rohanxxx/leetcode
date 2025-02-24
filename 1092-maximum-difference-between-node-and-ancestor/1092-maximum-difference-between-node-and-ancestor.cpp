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
    int maxDif;
    void dfs(TreeNode* root, int curMin, int curMax){

        if(!root) return;
        if(curMin == INT_MAX && curMax == INT_MIN){
            curMin = root->val;
            curMax = root->val;
            dfs(root->left, curMin, curMax);
            dfs(root->right, curMin, curMax);
            return;
        }
        maxDif = max(abs(curMax-root->val), maxDif);
        maxDif = max(abs(curMin-root->val), maxDif);
        // cout << "maxDif: " << maxDif << endl;
        
        curMax = max(curMax, root->val);
        curMin = min(curMin, root->val);
        dfs(root->left, curMin, curMax);
        dfs(root->right, curMin, curMax);
    }
    int maxAncestorDiff(TreeNode* root) {
        maxDif = 0;
        dfs(root, INT_MAX, INT_MIN);
        return maxDif;
    }
};