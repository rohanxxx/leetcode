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
    Node* cloneTree(Node* root) {
        if (root == nullptr) {
            return root;
        }

        Node* newRoot = new Node(root->val);

        // Queue for BFS traversal
        deque<pair<Node*, Node*>> queue;
        queue.push_back({root, newRoot});

        while (!queue.empty()) {
            pair<Node*, Node*> nodePair = queue.front();
            queue.pop_front();

            Node* oldNode = nodePair.first;
            Node* newNode = nodePair.second;

            for (Node* childNode : oldNode->children) {
                Node* newChildNode = new Node(childNode->val);

                // Copy each child node
                newNode->children.push_back(newChildNode);

                // Add the child nodes to the queue to copy their children
                queue.push_back({childNode, newChildNode});
            }
        }

        return newRoot;
    }
};