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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        unordered_map<int, int> mp;
        queue<TreeNode*> q; q.push(root);

        int level = 0;
        int levelCount = 0;
        int maxLevelSum = INT_MIN;
        while(!q.empty()){
            levelCount++;
            int size = q.size();
            int levelSum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                levelSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(maxLevelSum < levelSum){
                maxLevelSum = levelSum;
                level = levelCount;
            }
        }
        return level;
    }
};