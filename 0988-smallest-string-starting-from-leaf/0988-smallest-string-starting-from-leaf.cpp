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
    return lexicographically smallest string that starts at a leaf of this tree and ends at the root
 */
class Solution {
public:
    string dfs(TreeNode* node, string str){
        if(node == NULL){
            return "";
        }
        str.push_back((char)('a'+node->val));
        //check for leaf node
        if(node->left == NULL && node->right == NULL){
            reverse(str.begin(), str.end());
            return str;
        }

        string left = dfs(node->left, str);
        string right = dfs(node->right, str);

        if(left == ""){
            return right;
        }
        if(right == ""){
            return left;
        }

        return min(left, right);   
    }
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }
};