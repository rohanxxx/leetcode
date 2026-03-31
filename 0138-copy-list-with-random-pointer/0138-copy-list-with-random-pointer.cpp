class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        // Step 1: Interleave clones into original list
        Node* it = head;
        while(it){
            Node* dup = new Node(it->val);
            dup->next = it->next;
            it->next = dup;
            it = dup->next;
        }

        // Step 2: Fix random pointers
        it = head;
        while(it){
            Node* dup = it->next;
            if(it->random != nullptr){
                dup->random = it->random->next;
            } else {
                dup->random = nullptr;
            }
            it = dup->next;
        }

        // Step 3: Separate the two lists
        it = head;
        Node* clone = head->next;
        while(it){
            Node* dup = it->next;
            it->next = dup->next;
            if(dup->next != nullptr){
                dup->next = dup->next->next;
            } else {
                dup->next = nullptr;
            }
            it = it->next;
        }

        return clone;
    }
};