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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size, 0);
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                if(ans.size()%2){
                    level[size-i-1] = node->val;
                }
                else{
                    level[i] = node->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }

        /*for(int i = 0; i < ans.size(); i++){
            if(i%2) reverse(ans[i].begin(), ans[i].end());
        }*/

        return ans;
    }
};