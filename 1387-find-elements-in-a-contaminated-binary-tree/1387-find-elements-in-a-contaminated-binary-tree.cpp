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
class FindElements {
private:
    TreeNode* tree;
public:
    FindElements(TreeNode* root) {
        tree = root;
        TreeNode* temp = tree;

        if (temp->val == -1) temp->val = 0;
        queue<TreeNode*> q; q.push(temp);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(node->left != NULL) {
                node->left->val = node->val * 2 + 1;
                q.push(node->left);
            }
            if(node->right != NULL) {
                node->right->val = node->val * 2 + 2;
                q.push(node->right);
            }
        }
    }
    
    bool find(int target) {
        TreeNode* temp = tree;
        if(temp == NULL) return false;
        queue<TreeNode*> q; q.push(temp);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(node->val == target) return true;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */