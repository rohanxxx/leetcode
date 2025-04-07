/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode* > q; q.push(target);
        visited[target] = true;
        int cur_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(cur_level++ == k) break;
            for(int i = 0; i < size; i++){
                TreeNode* current = q.front(); q.pop();
                if(current->left && visited[current->left] == false){
                    visited[current->left] = true;
                    q.push(current->left);
                }
                if(current->right && visited[current->right] == false){
                    visited[current->right] = true;
                    q.push(current->right);
                }
                if(parent[current] && visited[parent[current]] == false){
                    visited[parent[current]] = true;
                    q.push(parent[current]);
                }
            }
        }

        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val); 
            q.pop();
        }
        return result;
    }
};