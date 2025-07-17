/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    void dfs(Node* root, vector<Node*>& container){
        if(root == NULL) return;
        dfs(root->left, container);
        container.push_back(root);
        dfs(root->right, container);
    }
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;

        vector<Node*> temp;
        dfs(root, temp);

        for (int i = 0; i < temp.size() - 1; i++) {
            temp[i]->right = temp[i + 1];
            temp[i + 1]->left = temp[i];
        }

        temp[0]->left = temp.back();
        temp.back()->right = temp[0];

        return temp[0];
     }
};