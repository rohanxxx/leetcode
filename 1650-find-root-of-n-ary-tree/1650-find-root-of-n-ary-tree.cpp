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

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {

        unordered_set<int> seen;

        // add all the child nodes into the set
        for (int i = 0; i < tree.size(); i++) {
            for (int j = 0; j < tree[i]->children.size(); j++) {
                seen.insert(tree[i]->children[j]->val);
            }
        }

        Node* root = nullptr;
        // find the node that is not in the child node set.
        for (int i = 0; i < tree.size(); i++) {
            if (seen.find(tree[i]->val) == seen.end()) {
                root = tree[i];
                break;
            }
        }
        return root;
    }
};