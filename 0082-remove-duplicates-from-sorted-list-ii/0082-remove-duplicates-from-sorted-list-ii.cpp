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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pred = new ListNode(-1, head);
        ListNode* prev = pred;
        ListNode* curr = pred->next;

        while(curr){
            bool dup = false;
            while(curr->next && curr->val == curr->next->val) {
                curr->next = curr->next->next;
                dup = true;
            }
            if(dup == true) {
                prev->next = curr->next;
                curr = curr->next;
                continue;
            }
            
            prev = curr;
            curr = curr->next;
        }

        return pred->next;
    }
};