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
    /*
         1 ->2 ->3 ->4 ->5
    */
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* Next = NULL;
        while(cur){
            Next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = Next;
        }
        return prev;
    }
};