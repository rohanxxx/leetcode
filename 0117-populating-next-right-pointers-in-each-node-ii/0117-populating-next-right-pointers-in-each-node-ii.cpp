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
        if(!root) return NULL;
        queue<Node*> q; q.push(root);
        while(!q.empty()){
            int curLevelSize = q.size();
            for(int i = 0; i < curLevelSize; i++){
                Node* curNode = q.front(); q.pop();
                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
                if(i+1 == curLevelSize){
                    curNode->next = NULL;
                }
                else{
                    curNode->next = q.front();
                }
            }
        }
        return root;
    }
};