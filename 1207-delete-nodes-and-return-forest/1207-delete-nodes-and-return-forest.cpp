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
        if(!root) return forest;
        
        unordered_set<int> deleteNodes(to_delete.begin(), to_delete.end());
        
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            TreeNode* currentNode = q.front(); q.pop();
            if(currentNode->left){
                q.push(currentNode->left);
                if(deleteNodes.find(currentNode->left->val) != deleteNodes.end()){
                    currentNode->left = NULL;
                }
            }
            if(currentNode->right){
                q.push(currentNode->right);
                if(deleteNodes.find(currentNode->right->val) != deleteNodes.end()){
                    currentNode->right = NULL;
                }
            }
            if(deleteNodes.find(currentNode->val) != deleteNodes.end()){
                if(currentNode->left){
                    forest.push_back(currentNode->left);
                }
                if(currentNode->right){
                    forest.push_back(currentNode->right);
                }
            }
        }
        if(deleteNodes.find(root->val) == deleteNodes.end()){
            forest.push_back(root);
        }
        return forest;
    }
};