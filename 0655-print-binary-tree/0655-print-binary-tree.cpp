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
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = dfs(root);
        int col = (1 << height) -1;
        
        vector<vector<string>> ans(height, vector<string>(col, ""));

        queue<pair<TreeNode*, int>> q; q.push({root, col/2});

        int depth = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                int index = q.front().second;
                int val = node->val;

                q.pop();

                ans[depth][index] = to_string(val);

                if (depth < height - 1) {
                    int offset = 1 << (height - depth - 2);

                    if (node->left)
                        q.push({node->left, index - offset});
                    if (node->right)
                        q.push({node->right, index + offset});
                }
            }
            depth++;
        }

        return ans;
    }
};