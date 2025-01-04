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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        
        while(temp){
            size++;
            temp = temp->next;
        }

        int stop = size - n;
        int i = 1;
        temp = head;

        if(n == 1 && size == 1) return NULL; 
        if(stop == 0) return head = head->next;
        
        while(temp){
            if(i == stop){
                temp->next = temp->next->next;
                return head;
            }
            temp = temp->next;
            i++;
        }

        return head;
    }
};