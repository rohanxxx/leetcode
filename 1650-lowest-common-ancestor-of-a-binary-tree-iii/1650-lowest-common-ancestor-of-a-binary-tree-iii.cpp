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

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map<int, bool> visited;
        while(p){
            visited[p->val] = true;
            p = p->parent;
        }

        while(q){
            if(visited[q->val]){
                return q;
            }
            visited[q->val];
            q = q->parent;
        }

        return NULL;
    }
};