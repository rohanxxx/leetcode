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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<vector<TreeNode*>> q;
        q.push({root});

        int dept = 0;
        while(!q.empty()){
            vector<TreeNode*> currLevel = q.front();
            q.pop();
            dept++;

            vector<TreeNode*> nextLevel;
            for(int i = 0; i < currLevel.size(); i++){
                if(currLevel[i]->left == NULL && currLevel[i]->right == NULL) return dept;
                if(currLevel[i]->left) nextLevel.push_back(currLevel[i]->left);
                if(currLevel[i]->right) nextLevel.push_back(currLevel[i]->right);
            }

            if(!nextLevel.empty()) q.push(nextLevel);
        }
        return -1;
    }
};