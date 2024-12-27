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
    bool isLeaf(TreeNode* root){
        return root->left == NULL && root->right == NULL;
    }

    void addLeaves(vector<int>& ans, TreeNode* root){
        if(isLeaf(root)){
            ans.push_back(root->val);
        }
        else{
            if(root->left != NULL){
                addLeaves(ans, root->left);
            }
            if(root->right != NULL){
                addLeaves(ans, root->right);
            }
        }
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        
        if(!isLeaf(root)) ans.push_back(root->val);
        
        TreeNode* t = root->left;

        // stores left boundary
        while(t != NULL){
            if(!isLeaf(t)) ans.push_back(t->val);
            
            if(t->left != NULL) t = t->left;
            else t = t->right;
        }

        addLeaves(ans, root);

        stack<int> stack;
        t = root->right;
        while(t != NULL){
            if(!isLeaf(t)) stack.push(t->val);

            if(t->right != NULL) t = t->right;
            else t = t->left;
        }

        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }

        return ans;
    }
};