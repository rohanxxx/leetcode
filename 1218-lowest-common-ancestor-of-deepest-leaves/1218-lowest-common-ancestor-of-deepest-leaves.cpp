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
    struct Obj {
        int depth;
        TreeNode* node;
        Obj (): depth(0), node(nullptr) {} 
        Obj (int val, TreeNode* curNode): depth(val), node(curNode) {} 
    };

    Obj* dfs(TreeNode* root){
        if(root == NULL){
            return new Obj(0, NULL);
        }

        Obj* leftSide = dfs(root->left);
        Obj* rightSide = dfs(root->right);

        if(leftSide->depth == rightSide->depth){
            leftSide -> depth = leftSide->depth+1;
            leftSide -> node = root;
            return leftSide;
            //new Obj(leftSide->depth+1, root);
        }

        if(leftSide->depth > rightSide->depth){
            leftSide -> depth = leftSide->depth+1;
            return leftSide;
            //return new Obj(leftSide->depth+1, leftSide->node);
        }

        rightSide->depth = rightSide->depth+1;
        return rightSide;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        Obj* lca = dfs(root);
        return lca->node;
    }
};