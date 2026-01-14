class Solution {
public:
//     1 2 3 4 5
    // 1 3 5
    // 2 4
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;                 // FIX: handle empty list

        ListNode* t1 = head;
        ListNode* t2 = new ListNode();
        ListNode* t3 = t2;                     // FIX: was t2->next (NULL). Start at dummy.

        while(t1){
            if(t1->next){
                ListNode* evenNode = t1->next; // FIX: save the even node first

                t3->next = evenNode;           // FIX: append even node
                t3 = t3->next;                 // FIX: only move t3 when you appended

                t1->next = evenNode->next;     // FIX: remove even from odd chain
            }
            // t3 = t3->next; 
            t1 = t1->next;
        }

        t3->next = nullptr;                    // FIX: terminate even list (prevents cycles)

        t1 = head;
        while(t1->next){
            t1 = t1->next;
        }
        t1->next = t2->next;
        return head;
    }
};