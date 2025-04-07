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
    TreeNode* markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int& start){
        queue<TreeNode*> q; q.push(root);
        TreeNode* startNode;
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(node->val == start) startNode = node;
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return startNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = markParent(root, parent, start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode* > q; q.push(startNode); 
        visited[startNode] = true;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                if(node->left && visited[node->left] == false){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && visited[node->right] == false){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && visited[parent[node]] == false){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            time++;
        }
        return time-1;
    }
};