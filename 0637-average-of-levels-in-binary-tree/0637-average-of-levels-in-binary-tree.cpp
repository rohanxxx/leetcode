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
    void bfs(TreeNode* root, vector<double>& ans){
        if(root == NULL) return;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            int n = q.size();
            long long curSum = 0;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                
                q.pop();

                curSum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back((double)curSum / (double)n);
        }
        return;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        bfs(root, ans);
        return ans;
    }
};