/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
 /*
    0 1 2 3 4 5 6 7 8 9
    g r t a a b c p o e

    0 1 2 3 4 5 6 7 
    a b c e f g h i j k l m
 */
class Solution {
public:
    string dfs(RopeTreeNode* node){
        if(node == NULL){
            return "";
        }
        string left_string = dfs(node->left);
        string right_string = dfs(node->right);
        string cur_string = node->val;

        return cur_string+left_string+right_string;
    }
    char getKthCharacter(RopeTreeNode* root, int k) {
        string root_string = dfs(root);
        return root_string[k-1];
    }
};