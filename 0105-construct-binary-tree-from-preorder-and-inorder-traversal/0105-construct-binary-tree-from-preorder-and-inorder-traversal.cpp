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
    int preOrderIndex = 0;
    unordered_map<int, int> inorderIndex;
    
    TreeNode* convert(vector<int>& preorder, int left, int right){
        if(left > right) return NULL;
        int rootValue = preorder[preOrderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        root->left = convert(preorder, left, inorderIndex[rootValue]-1);
        root->right = convert(preorder, inorderIndex[rootValue]+1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) inorderIndex[inorder[i]] = i;
        return convert(preorder, 0, preorder.size()-1);
    }
};