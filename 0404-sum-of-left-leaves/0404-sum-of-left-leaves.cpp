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
    bool isLeaf(TreeNode* root){
        return (root->left == NULL && root->right == NULL);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        if(isLeaf(root)) return 0;
        
        int leafSum = 0;

        queue<TreeNode*> q;
        q.push(root);

        //TC:O(Diameter of Tree at max N)
        while(!q.empty()){
            TreeNode* curNode = q.front();
            
            q.pop();

            if(curNode->left) {
                q.push(curNode->left);
                if(isLeaf(curNode->left)){
                    leafSum += curNode->left->val;
                }
            }
            if(curNode->right) q.push(curNode->right);
        }

        return leafSum;
    }
};