/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    vector<Node*> dfs(Node* head){
        Node* temp = head;
        Node* tail = NULL;
        while(temp){
            if(temp->child){
                vector<Node*> pair = dfs(temp->child);
                Node* child = pair[0];
                Node* childTail = pair[1];

                Node* originalNext = temp->next;

                child->prev = temp;
                temp->next = child;
                temp->child = NULL;

                childTail->next = originalNext;

                if(originalNext){
                    originalNext->prev = childTail;
                }
                temp = childTail;
            }
            tail = temp;
            temp = temp->next;
        }

        return {head, tail};
    }
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
};