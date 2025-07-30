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
    void dfs(TreeNode* root, vector<int>& v){
        if(root == NULL) return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        //TC: O(N+M)
        dfs(root1, v1);
        dfs(root2, v2);

        vector<int> ans;
        int i = 0, j = 0;
        int n1 = v1.size(), n2 = v2.size();
        //TC:O(N+M)
        while(i < n1 && j < n2){
            if(v1[i] <= v2[j]) ans.push_back(v1[i++]);
            else ans.push_back(v2[j++]);
        }
        
        while(i < n1) ans.push_back(v1[i++]);
        while(j < n2) ans.push_back(v2[j++]);
        
        return ans;
    }
};