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
    void dfs(TreeNode* root, TreeNode* subRoot, vector<TreeNode*>& mp){
        if(root == NULL) return;
        if(root->val == subRoot->val){
            mp.push_back(root);
        }
        dfs(root->left, subRoot, mp);
        dfs(root->right, subRoot, mp);
    }
    bool dfs(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        bool leftCheck = dfs(p->left, q->left);
        bool rightCheck = dfs(p->right, q->right);
        return (p->val == q->val) && leftCheck && rightCheck;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> mp;
        dfs(root, subRoot, mp);
        int n = mp.size();
        //bool check = false;
        for(int i = 0; i < n; i++){
            if(dfs(mp[i], subRoot) == true){
                return true;
            }
        }
        return false;
    }
};