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
/*
                                    1 -> NULL
                                2 ->       3 -> NULL
                            4->   5->       6->   7 -> NULL

    queue<Node*> q; push(1);
    Node* prev = new Node()

    while(!q.empty()){
        int size = q.size();
        for(i -> size){
            Node* curNode = q.front(); q.pop();
            prev->next = curNode;
            prev = prev->next;
            if(curNode->left){
                q.push()
            }
        }
    }
*/
class Solution {
public:
    Node* connect(Node* root) {
        //edge case
        if(root == NULL) return root;
        
        queue<Node*> q; q.push(root);
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