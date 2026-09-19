/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */
/*
    tree represents val and random_index

*/
class Solution {
public:
    void dfs1(Node* node, unordered_map<Node*, NodeCopy*>& map){
        if(node == NULL){
            return;
        }
        map[node] = new NodeCopy(node->val);
        
        dfs1(node->left, map);
        dfs1(node->right, map);
        
        if(node->left){
            map[node]->left = map[node->left];
        }
        if(node->right){
            map[node]->right = map[node->right];
        }
        return;
    }

    void dfs2(Node* node, unordered_map<Node*, NodeCopy*>& map){
        if(node == NULL){
            return;
        }

        if(node->random){
            map[node]->random = map[node->random];
        }

        dfs2(node->left, map);
        dfs2(node->right, map);
        return;
    }

    NodeCopy* copyRandomBinaryTree(Node* root) {
        Node* temp = root;
        unordered_map<Node*, NodeCopy*> map;

        dfs1(temp, map);
        
        temp = root;
        dfs2(temp, map);

        return map[root];
    }
};