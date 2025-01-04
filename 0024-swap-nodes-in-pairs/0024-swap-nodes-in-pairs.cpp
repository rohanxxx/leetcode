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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prevNode = dummy;

        while(head && head->next){
            ListNode* firstNode = head;
            ListNode* secondNode = head->next;

            // now swap operation
            prevNode->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            prevNode = firstNode;
            head = firstNode->next;
        }

        return dummy->next;
    }
};