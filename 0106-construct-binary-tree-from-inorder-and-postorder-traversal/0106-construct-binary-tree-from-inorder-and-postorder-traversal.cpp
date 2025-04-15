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
    int postorderIndex = 0;
    unordered_map<int, int> inorderIndex;
    TreeNode* binarySearch(vector<int>& postorder, int left, int right){
        if(left > right) return NULL;
        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);
        root->right = binarySearch(postorder, inorderIndex[rootVal]+1, right);
        root->left = binarySearch(postorder, left, inorderIndex[rootVal]-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postorderIndex = n-1;
        for(int i = 0; i < n; i++){
            inorderIndex[inorder[i]] = i;
        }
        return binarySearch(postorder, 0, n-1);
    }
};