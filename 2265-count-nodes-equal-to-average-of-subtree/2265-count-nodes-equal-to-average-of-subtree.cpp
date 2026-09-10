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
    given root
    return the number of nodes 
    where the values of the node is equal to the average of the 
    values in its subtree

    Input: root = [4,8,5,0,1,null,6]
    Output: 5

        4
       / \
      8   5
     / \.  \
    0.  1.  6

    pair<int, int> dfs(root, count);
 */
class Solution {
public:
    //return {nodeCountAve, nodeCount, sumOfSubTree}
    vector<int> dfs(TreeNode* node){
        if(!node){
            return {0,0,0};
        }

        int sum = node->val;
        vector<int> leftRet = dfs(node->left);
        vector<int> rightRet = dfs(node->right);

        sum += (leftRet[2] + rightRet[2]);
        int nodeCount = leftRet[1] + rightRet[1] + 1;

        int nodeCountAvg = leftRet[0] + rightRet[0];

        if((int)sum / nodeCount == (int)node->val){
            nodeCountAvg++;
        }
        return {nodeCountAvg, nodeCount, sum};
    }
    int averageOfSubtree(TreeNode* root) {
        vector<int> ret = dfs(root);
        return ret[0];
    }
};