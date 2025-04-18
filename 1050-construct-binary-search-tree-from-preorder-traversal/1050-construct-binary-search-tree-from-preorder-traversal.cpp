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
    int index;
    TreeNode* bst(vector<int>& preorder, int lo, int hi){
        if(index == preorder.size()) return NULL;
        TreeNode* node = NULL;
        int cur = preorder[index];
        if(cur > lo && cur < hi){
            node = new TreeNode(cur);
        }
        else{
            return NULL;
        }

        index++;
        node->left = bst(preorder, lo, cur);
        node->right = bst(preorder, cur, hi);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        index = 0;
        return bst(preorder, INT_MIN, INT_MAX);
    }
};