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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxWidth = INT_MIN;
        queue<pair<TreeNode*, unsigned long long>> q; q.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*, unsigned long long> head = q.front();
            pair<TreeNode*, unsigned long long> curElement;
            int currentLevelSize = q.size();
            for(int i = 0; i < currentLevelSize; i++){
                curElement = q.front(); q.pop();
                TreeNode* node = curElement.first;
                if(node->left) q.push({node->left, 2*(unsigned long long)curElement.second});
                if(node->right) q.push({node->right, 2*(unsigned long long)curElement.second+1});
            }
            
            maxWidth = max(maxWidth, (int)(curElement.second - head.second + 1));
        }

        return maxWidth;
    }
};