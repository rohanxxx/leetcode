/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);

        ListNode* t1 = before;
        //ListNode* t2 = middle;
        ListNode* t3 = after;

        while(head){
            ListNode* nxt = head->next;
            head->next = NULL;
            if(head->val < x){
                t1->next = head;
                t1 = t1->next;
            }
            else{
                t3->next = head;
                t3 = t3->next;
            }

            head = nxt;
        }

        t3->next = NULL;
        if(after->next){
            t1->next = after->next;
        }

        return before->next;
    }
};