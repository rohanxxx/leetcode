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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        unordered_map<int, int> depthMap;
        queue<TreeNode*> q; q.push(root);

        int depth = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                depthMap[depth] += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++;
        }

        depth = 0;
        root->val = 0;
        
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                int curSum = 0;
                if(node->left){
                    curSum += node->left->val;
                    q.push(node->left);
                }
                if(node->right){
                    curSum += node->right->val;
                    q.push(node->right);
                }

                if(node->left){
                    node->left->val = (depthMap[depth+1] - curSum);
                }
                if(node->right){
                    node->right->val = (depthMap[depth+1] - curSum);
                }
            }
            depth++;
        }

        return root;
    }
};