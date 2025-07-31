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
    struct nodeDepth {
        int depth;
        TreeNode* node;

        nodeDepth(): depth(0), node(nullptr) {}
        nodeDepth(int val, TreeNode* curNode): depth(val), node(curNode) {}
    };

    nodeDepth* dfs(TreeNode* root){
        if(!root){
            return new nodeDepth();
        }

        nodeDepth* leftSide = dfs(root->left);
        nodeDepth* rightSide = dfs(root->right);

        if(leftSide->depth == rightSide->depth){
            leftSide->depth = leftSide->depth + 1;
            leftSide -> node = root;
            return leftSide;
        }

        if(leftSide->depth > rightSide->depth){
            leftSide->depth = leftSide->depth+1;
            return leftSide;
        }

        rightSide->depth = rightSide->depth+1;
        return rightSide;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        nodeDepth* subTree = dfs(root);
        return subTree->node;
    }
};