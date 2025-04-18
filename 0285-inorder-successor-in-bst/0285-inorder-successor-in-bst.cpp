/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void bst(TreeNode* node, vector<TreeNode*>& inorder){
        if(node == NULL) return;
        bst(node->left, inorder);
        inorder.push_back(node);
        bst(node->right, inorder);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> inorder;
        bst(root, inorder);
        int index = 0;
        for(int i = 0; i < inorder.size(); i++){
            cout << inorder[i]->val << " ";
            
            if(inorder[i]->val == p->val){
                index = (i+1);
                break;
            }
        }
        cout << endl;
        if(index == inorder.size()) return NULL;
        return inorder[index];
    }
};