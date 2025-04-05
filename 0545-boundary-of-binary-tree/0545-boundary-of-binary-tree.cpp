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
    bool isLeaf(TreeNode* node){
        if(node->left == NULL && node->right == NULL) return true;
        return false;
    }
    void addLeaves(vector<int>& ans, TreeNode* node){
        if(!node) return;
        if(isLeaf(node)) {
            ans.push_back(node->val);
        }
        else{
            if(node->left) addLeaves(ans, node->left);
            if(node->right) addLeaves(ans, node->right);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        if(!isLeaf(root)) ans.push_back(root->val);
        TreeNode* t = root->left;
        while(t != NULL){
            if(!isLeaf(t)) ans.push_back(t->val);
            if(t->left) t = t->left;
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