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
    int minimumLevel(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        //{level, minlevelSum}
        pair<int, int> p = {INT_MAX, INT_MAX};
        queue<TreeNode*> q; q.push(root);

        int level = 0;
        while(!q.empty()){
            level++;
            int size = q.size();
            long long levelSum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                levelSum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            if(levelSum < p.second){
                p.first = level;
                p.second = levelSum;
            }
        }
        return p.first;
    }
};