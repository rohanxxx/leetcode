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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        if(root == NULL) return forest;

        unordered_set<int> set(to_delete.begin(), to_delete.end());

        queue<TreeNode*> q; q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();

            if(node->left){
                q.push(node->left);
                if(set.find(node->left->val) != set.end()){
                    node->left = NULL;
                }
            }
            if(node->right){
                q.push(node->right);
                if(set.find(node->right->val) != set.end()){
                    node->right = NULL;
                }
            }

            if(set.find(node->val) != set.end()){
                if(node->left){
                    forest.push_back(node->left);
                }
                if(node->right){
                    forest.push_back(node->right);
                }
            }
        }

        if(set.find(root->val) == set.end()){
            forest.push_back(root);
        }

        return forest;
    }
};