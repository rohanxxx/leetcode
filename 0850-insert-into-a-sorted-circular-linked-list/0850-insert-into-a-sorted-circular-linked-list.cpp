/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }

        Node* prev = head;
        Node* curr = head->next;
        bool toInsert = false;

        do {
            cout << "line 36" << endl;
            cout << "prev->val: " << prev->val << endl;
            if (prev->val <= insertVal && insertVal <= curr->val) {
                // Case 1).
                cout << "line 38" << endl;
                toInsert = true;
            } else if (prev->val > curr->val) {
                // Case 2).
                cout << "line 42" << endl;
                if (insertVal >= prev->val || insertVal <= curr->val){
                    cout << "line 44" << endl;
                    toInsert = true;
                }
            }

            if (toInsert) {
                prev->next = new Node(insertVal, curr);
                return head;
            }

            prev = curr;
            curr = curr->next;
        } while (prev != head);

        // Case 3).
        prev->next = new Node(insertVal, curr);
        return head;
    }
};