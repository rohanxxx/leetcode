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
    int levelMedian(TreeNode* root, int level) {
        if(root == NULL){
            return -1;
        }
        
        queue<TreeNode*> q;
        q.push(root);

        vector<int> vec;
        int curLevel = 0;
        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front(); q.pop();

                if(curLevel == level){
                    vec.push_back(node->val);
                    continue;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(curLevel == level){
                break;
            }
            curLevel++;
        }

        if(vec.size() == 0){
            return -1;
        }

        sort(vec.begin(), vec.end());

        int ans = vec[(int)vec.size()/2];

        return ans;
    }
};