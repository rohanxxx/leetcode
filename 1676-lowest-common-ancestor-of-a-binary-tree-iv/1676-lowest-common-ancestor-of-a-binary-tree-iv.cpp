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
 /*
    
 */

 /*
    1) both left and right has lca and set is empty left then return the cur node
    2) both left and right has lca but the set isn't empty still return the cur node
    3) if left or right lca case then return the left || right that has lca
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* node, unordered_set<int>& set){
        if(node == NULL){
            return NULL;
        }

        TreeNode* left = dfs(node->left, set);
        TreeNode* right = dfs(node->right, set);
        
        if((left && right) || (set.find(node->val) != set.end())){
            return node;
        }
        
        if(left == NULL){
            return right;
        }
        return left;
    }
    //TC: O(N+M)
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<int> set;
        //TC: O(M)
        for(int i = 0; i < nodes.size(); i++){
            set.insert(nodes[i]->val);
        }
        //TC: O(N)
        return dfs(root, set);
    }
};