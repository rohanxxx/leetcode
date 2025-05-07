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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL){
            return vector<vector<int>>();
        }
        
        map<int, vector<int>> map;
        queue<pair<TreeNode* ,int>> q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* curNode = q.front().first;
            int lineNumber = q.front().second;
            
            q.pop();

            map[lineNumber].push_back(curNode->val);
            
            if(curNode->left){
                q.push({curNode->left, lineNumber-1});
            }
            if(curNode->right){
                q.push({curNode->right, lineNumber+1});
            }
        }

        vector<vector<int>> ans;
        for(auto it: map){
            //vector<int> temp = it.second;
            ans.push_back(it.second);
        }
        return ans;
    }
};