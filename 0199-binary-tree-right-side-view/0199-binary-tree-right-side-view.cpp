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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};
        queue<vector<TreeNode*>> q;
        q.push({root});

        vector<int> rightView;
        while(!q.empty()){
            vector<TreeNode*> level = q.front();
            rightView.push_back(level.back()->val);
            q.pop();

            vector<TreeNode*> temp;
            for(int i = 0; i < level.size(); i++){
                if(level[i]->left) temp.push_back(level[i]->left);
                if(level[i]->right) temp.push_back(level[i]->right);
            }

            if(!temp.empty()) q.push(temp);
        }
        return rightView;
    }
};