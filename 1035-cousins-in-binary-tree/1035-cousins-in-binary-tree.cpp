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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,vector<int>> map;

        if(root == NULL) return false;

        int depth = 1;
        map[root->val] = {-1, 0};
        queue<TreeNode*> q; q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curNode = q.front(); q.pop();
                if(curNode->left){
                    q.push(curNode->left);
                    map[curNode->left->val] = {curNode->val, depth};
                }
                if(curNode->right){
                    q.push(curNode->right);
                    map[curNode->right->val] = {curNode->val, depth};
                }
            }
            depth++;
        }

        if(map.find(x) != map.end() && map.find(y) != map.end()){
            if(map[x][0] != map[y][0] && map[x][1] == map[y][1]) return true;
        }

        return false;
    }
};