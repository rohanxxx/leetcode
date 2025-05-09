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
        if (root == nullptr) {
            return root;
        }
        // Start with the root node. There are no next pointers
        // that need to be set up on the first level
        Node* leftmost = root;
        // Once we reach the final level, we are done
        while (leftmost->left != nullptr) {
            // Iterate the "linked list" starting from the head
            // node and using the next pointers, establish the
            // corresponding links for the next level
            Node* head = leftmost;
            while (head != nullptr) {
                // CONNECTION 1
                head->left->next = head->right;
                // CONNECTION 2
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }
                // Progress along the list (nodes on the current level)
                head = head->next;
            }
            // Move onto the next level
            leftmost = leftmost->left;
        }
        return root;
    }
};