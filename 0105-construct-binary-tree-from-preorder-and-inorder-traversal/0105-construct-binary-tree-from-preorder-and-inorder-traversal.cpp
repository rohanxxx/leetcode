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
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndex;
    TreeNode* binarySearch(vector<int>& preorder, int left, int right){
        if(left > right) return NULL;
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        root->left = binarySearch(preorder, left, inorderIndex[rootVal]-1);
        root->right = binarySearch(preorder, inorderIndex[rootVal]+1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            inorderIndex[inorder[i]] = i;
        }
        return binarySearch(preorder, 0, n-1);
    }
};