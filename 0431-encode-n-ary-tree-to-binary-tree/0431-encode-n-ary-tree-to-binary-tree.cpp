/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* rootNode = new TreeNode(root->val);
        if(!root->children.empty()){
            rootNode->left = encode(root->children[0]);
        }

        TreeNode* curr = rootNode->left;
        for(int i = 1; i < root->children.size(); i++){
            curr->right = encode(root->children[i]);
            curr = curr->right;
        }

        return rootNode;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        Node* rootNode = new Node(root->val);
        TreeNode* curr = root->left;
        while(curr){
            rootNode->children.push_back(decode(curr));
            curr = curr->right;
        }

        return rootNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));