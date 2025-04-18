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
class BSTIterator {
private:
    int index;
    vector<int> inorder;
    void bst(TreeNode* root){
        if(root == NULL) return;
        bst(root->left);
        inorder.push_back(root->val);
        bst(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        this->bst(root);
        if(this->inorder.size() > 0) this->index = 0;
        else this->index = 1;
    }
    
    int next() {
        if(index >= inorder.size()) return NULL;
        return this->inorder[this->index++];
    }
    
    bool hasNext() {
        if(this->index >= this->inorder.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */