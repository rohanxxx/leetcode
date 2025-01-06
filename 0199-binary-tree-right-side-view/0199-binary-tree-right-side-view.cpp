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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q; q.push(root);
        
        vector<int> ans;
        while(!q.empty()){
            int qSize = q.size();
            int rightSide = INT_MIN;
            for(int i = 0; i < qSize; i++){
                TreeNode* node = q.front(); q.pop();
                rightSide = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(rightSide != INT_MIN){
                ans.push_back(rightSide);
            }
        }

        return ans;
    }
};