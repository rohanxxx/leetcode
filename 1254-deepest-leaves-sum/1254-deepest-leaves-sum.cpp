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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode* > q; q.push(root);
        int maxLeafSum = 0;
        while(!q.empty()){
            int size = q.size();
            int leafSum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                if(!node->left && !node->right){
                    leafSum += node->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            // maxLeafSum = max(maxLeafSum, leafSum);
            if(q.empty()) maxLeafSum = leafSum;
        }
        return maxLeafSum;
    }
};