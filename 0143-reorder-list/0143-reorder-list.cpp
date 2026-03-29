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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return;
        }

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        //find the mid
        //TC: O(N/2)
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(prev){
            prev->next = NULL;
        }

        prev = NULL;
        ListNode* cur = slow;
        ListNode* Next = NULL;
        //reverse the second Half
        while(cur){
            Next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = Next;
        }

        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        ListNode* prevFirst = NULL;
        ListNode* prevSecond = NULL;
        while(firstHalf && secondHalf){
            prevFirst = firstHalf;
            firstHalf = firstHalf->next;

            prevSecond = secondHalf;
            secondHalf = secondHalf->next;

            prevFirst->next = prevSecond;
            if(firstHalf){
                prevSecond->next = firstHalf;
            }
        }

        return;
    }
};