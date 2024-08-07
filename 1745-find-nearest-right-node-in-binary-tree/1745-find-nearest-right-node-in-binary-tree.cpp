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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if(!root) return NULL;
        queue<TreeNode*> q; q.push(root);
        
        vector<TreeNode*> rightMost;
        bool check = false;
        
        while(!q.empty()){
            
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                if(node->val == u->val || check){
                    rightMost.push_back(node);
                    check = true;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            if(check == true){
                if(rightMost.size() < 2) return NULL;
                return rightMost[1];
            }
        }

        return NULL;
    }
};