/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited){
        if(node == NULL) return NULL;
        if(visited[node] != NULL){
            return visited[node];
        }
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        for(Node* n: node->neighbors){
            cloneNode->neighbors.push_back(dfs(n, visited));
        }
        return cloneNode;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        Node* cloneNode = dfs(node, visited);
        return cloneNode;
    }
};