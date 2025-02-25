class Solution {
    int postorderIndex;
    unordered_map<int, int> mp;

public:
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int left, int right) {
        if (left > right) return NULL;
        int root_val = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(root_val);
        int index = mp[root_val];
        root->right = helper(postorder, inorder, index + 1, right);
        root->left = helper(postorder, inorder, left, index - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        postorderIndex = n - 1;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return helper(postorder, inorder, 0, n - 1);
    }
};