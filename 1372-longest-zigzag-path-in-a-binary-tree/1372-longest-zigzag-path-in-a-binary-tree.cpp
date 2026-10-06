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
    0 -> means no direction
    1 -> means left
    2 -> means right
 */
class Solution {
public:
    int ans = 0;
    int dfs(int dir, TreeNode* node){
        int ret = 0;
        if(dir == 0){
            if(node->left){
                ret = max(ret, 1 + dfs(1, node->left));
            }
            if(node->right){
                ret = max(ret, 1 + dfs(2, node->right));
            }
        }
        //coming from left
        if(dir == 1){
            if(node->left){
                //same direction again, so this is a new path starting at node
                //it can't extend the zigzag we came in on, so only update ans
                ans = max(ans, 1 + dfs(1, node->left));
            }
            if(node->right){
                ret = max(ret, 1 + dfs(2, node->right));
            }
        }
        //coming from right
        if(dir == 2){
            if(node->left){
                ret = max(ret, 1 + dfs(1, node->left));
            }
            if(node->right){
                //same direction again, so this is a new path starting at node
                ans = max(ans, 1 + dfs(2, node->right));
            }
        }

        return ret;
    }
    int longestZigZag(TreeNode* root) {
        ans = max(ans, dfs(0, root));
        return ans;
    }
};