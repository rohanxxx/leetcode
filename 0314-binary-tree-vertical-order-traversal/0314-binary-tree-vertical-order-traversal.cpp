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
        if(!root) return vector<vector<int>>();
        unordered_map<int, vector<int>> map;
        int minPoint = 0, maxPoint = 0;

        queue<pair<TreeNode*, int>> q; q.push({root, 0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int point = q.front().second;
            q.pop();

            map[point].push_back(node->val);
            minPoint = min(minPoint, point);
            maxPoint = max(maxPoint, point);

            if(node->left) q.push({node->left, point-1});
            if(node->right) q.push({node->right, point+1});
        }

        vector<vector<int>> ans;
        while(minPoint <= maxPoint){
            ans.push_back(map[minPoint]);
            minPoint++;
        }
        return ans;
    }
};