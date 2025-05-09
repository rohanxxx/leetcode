/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //edge case
        if(root == NULL) return root;
        
        queue<Node*> q; q.push(root);

        //TC: O(N)
        //TC: O(max(q.size()))
        while(!q.empty()){
            int size = q.size();
            Node* prev = new Node();
            for(int i = 0; i < size; i++){
                Node* curNode = q.front(); q.pop();
                prev->next = curNode;
                prev = prev->next;
                if(curNode->left){
                    q.push(curNode->left);
                }
                if(curNode->right){
                    q.push(curNode->right);
                }
            }
            
            //last node points to null
            prev->next = NULL;
        }

        return root;
    }
};