/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
/*
    in bst return the in-order successor of that node
    the successor of a node is the node with the smallest key greater than the node val

    have direct access to the node, but not the root,
    each node will have the reference to it's parent
*/
class Solution {
public:
    Node* ans;
    void dfs(Node* node, int& target, unordered_map<int, int>& visited){
        if(!node) return;
        //if visited then return immediately
        if(visited.find(node->val) != visited.end()){
            return;
        }
        visited[node->val] = 1;
        // successor must be strictly greater
        if (node->val > target) {
            if (ans == NULL) {
                ans = node;
            } else {
                if (ans->val > node->val) {
                    ans = node;
                }
            }
        }
        dfs(node->parent, target, visited);
        dfs(node->left, target, visited);
        dfs(node->right, target, visited);
    }
    Node* inorderSuccessor(Node* node) {
        if(!node) return NULL;

        ans = NULL;
        unordered_map<int, int> visited;

        visited[node->val] = 1;
        dfs(node->parent, node->val, visited);
        dfs(node->right, node->val, visited);
        return ans;
    }
};

/*class Solution {
public:
    Node* ans;
    void dfs(Node* node, int& target, unordered_map<int, int>& visited){
        if(!node) return;
        if(visited.find(node->val) != visited.end()) return;
        visited[node->val] = 1;

        // successor must be strictly greater than target
        if (node->val > target) {
            if (ans == NULL) {
                ans = node;
            } else {
                if (ans->val > node->val) {
                    ans = node;
                }
            }
        }

        dfs(node->parent, target, visited);
        dfs(node->left, target, visited);
        dfs(node->right, target, visited);
    }

    Node* inorderSuccessor(Node* node) {
        if(!node) return NULL;

        ans = NULL;
        unordered_map<int, int> visited;

        visited[node->val] = 1;
        dfs(node->parent, node->val, visited);
        dfs(node->right, node->val, visited);
        return ans;
    }
};
*/