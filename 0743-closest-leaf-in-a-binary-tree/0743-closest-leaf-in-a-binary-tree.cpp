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
    TreeNode* bfs(TreeNode* root, int& k, unordered_map<TreeNode*, TreeNode*>& parent){
        TreeNode* start = NULL;
        queue<TreeNode*> q; q.push(root);
        parent[root] = NULL;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == k) start = node;

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        return start;
    }
    int findClosestLeaf(TreeNode* root, int k) {
        if(root == NULL) return -1;

        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* start = bfs(root, k, parent);

        if(start == NULL) return -1;

        unordered_map<TreeNode*, bool> seen;
        
        queue<TreeNode*> q; q.push(start);
        seen[start] = true;
        //seen[root] = true;

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            //check whether if it is a leaf node or not
            if(node->left == NULL && node->right == NULL){
                return node->val;
            }

            if(node->left && seen[node->left] == false){
                q.push(node->left);
                seen[node->left] = true;
            }

            if(node->right && seen[node->right] == false){
                q.push(node->right);
                seen[node->right] = true;
            }

            if(parent[node] && seen[parent[node]] == false){
                q.push(parent[node]);
                seen[parent[node]] = true;
            }
        }

        return -1;
    }
};