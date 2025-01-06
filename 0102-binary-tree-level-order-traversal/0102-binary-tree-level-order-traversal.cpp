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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q; q.push(root);
        vector<vector<int>> result;

        while(!q.empty()){
            int qSize = q.size();
            vector<int> currentLevel;
            for(int i = 0; i < qSize; i++){
                TreeNode* node = q.front(); q.pop();
                currentLevel.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(!currentLevel.empty()) result.push_back(currentLevel);
        }

        return result;
    }
};