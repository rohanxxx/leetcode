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
    string dfs(TreeNode* node, string& str){
        if(node == NULL){
            return "";
        }
        str.push_back((char)('a'+node->val));
        //check for leaf node
        if(node->left == NULL && node->right == NULL){
            string word = str;
            reverse(word.begin(), word.end());
            str.pop_back();
            return word;
        }

        string left = dfs(node->left, str);
        string right = dfs(node->right, str);

        str.pop_back();

        if(left != "" && right != ""){
            return min(left, right);
        }
        if(left == ""){
            return right;
        }
        return left;
    }
    string smallestFromLeaf(TreeNode* root) {
        string str = "";
        return dfs(root, str);
    }
};