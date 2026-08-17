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
        while(p){
            Node* parent = p->parent;
            p->parent = NULL;
            p = parent; 
        }

        while(q->parent){
            q = q->parent;
        }

        return q;
    }
};