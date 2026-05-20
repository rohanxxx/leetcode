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
        vector<TreeNode*> ans;
        unordered_set<int> set(to_delete.begin(), to_delete.end());

        queue<TreeNode*> q;
        q.push(root);

        if(set.find(root->val) == set.end()){
            ans.push_back(root);
        }
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(set.find(node->val) != set.end()){
                if(node->left && set.find(node->left->val) == set.end()){
                    ans.push_back(node->left);
                }
                if(node->right && set.find(node->right->val) == set.end()){
                    ans.push_back(node->right);
                }
            }

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }

            if(node->left && set.find(node->left->val) != set.end()){
                node->left = NULL;
            }

            if(node->right && set.find(node->right->val) != set.end()){
                node->right = NULL;
            }
        }

        return ans;
    }
};