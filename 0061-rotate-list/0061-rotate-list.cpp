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
 /*

    3 2 1 0
    1 2 3 4 5 -> 1 2 3 4 5 
    make it a cycle 
    n-(k%n)
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int n = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            n++;
            prev = temp;
            temp = temp->next;
        }
        
        prev->next = head; //makes it a cycle
        
        int newHeadIndex = n-(k%n);
        temp = head;

        while(newHeadIndex){
            prev = temp;
            temp = temp->next;
            newHeadIndex--;
        }

        head = temp;
        prev->next = NULL;
        return head;
    }
};