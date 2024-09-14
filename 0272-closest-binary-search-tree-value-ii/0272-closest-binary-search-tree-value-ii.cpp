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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        TreeNode* temp = root;
        queue<TreeNode*> q;
        q.push(temp);

        vector<double> dif;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                dif.push_back(abs(double(node->val)-target));
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        sort(dif.begin(), dif.end());

        vector<int> ans;
        temp = root;
        q.push(temp);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                double curDif = abs(double(node->val)-target);
                if(find(dif.begin(), dif.begin()+k, curDif) != dif.begin()+k){
                    ans.push_back(node->val);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return ans;

    }
};