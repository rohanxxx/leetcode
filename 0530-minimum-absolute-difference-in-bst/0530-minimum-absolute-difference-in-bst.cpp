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

    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return -1;
        queue<TreeNode*> q; q.push(root);
        vector<int> node;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front(); q.pop();
                node.push_back(temp->val);
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
        }

        int minDif = INT_MAX;
        sort(node.begin(), node.end());
        for(int i = 1; i < node.size(); i++){
            minDif = min(minDif, abs(node[i]-node[i-1]));
        }
        return minDif;
    }
};