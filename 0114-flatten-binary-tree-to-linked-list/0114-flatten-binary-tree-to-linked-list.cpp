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
    vector<TreeNode* > preorder;
    void dfs(TreeNode* currentNode){
        if(currentNode == NULL) return;

        TreeNode* left  = currentNode->left;
        TreeNode* right = currentNode->right;
        
        currentNode->left = NULL;
        currentNode->right = NULL;

        preorder.push_back(currentNode);

        dfs(left);
        dfs(right);
    }
    void flatten(TreeNode* root) {
        dfs(root);
        // cout << "preorder.size(): " << preorder.size() << endl;
        TreeNode* temp = root;
        for(int i = 1; i < preorder.size(); i++){
            // temp->left = NULL;
            temp->right = preorder[i];
            temp = temp->right;
        }
    }
};