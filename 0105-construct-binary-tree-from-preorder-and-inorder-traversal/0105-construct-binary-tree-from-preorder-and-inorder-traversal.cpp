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
    int preorderIndex;
    unordered_map<int, int> inorderIndex;
    TreeNode* bst(vector<int>& preorder, int left, int right){
        if(left > right) return NULL;
        int nodeVal = preorder[preorderIndex++];
        TreeNode* node = new TreeNode(nodeVal);
        node->left = bst(preorder, left, inorderIndex[nodeVal]-1);
        node->right = bst(preorder, inorderIndex[nodeVal]+1, right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        int n = preorder.size();
        for(int i = 0; i < n; i++){
            inorderIndex[inorder[i]] = i;
        }
        return bst(preorder, 0, n-1);
    }
};