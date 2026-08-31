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
    k = 1
    i = 1
    prev_i = -k+2 = 1
    1 2 3 4 5
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int listLength = 0;
        ListNode* frontNode;
        ListNode* endNode;
        ListNode* currentNode = head;
        while (currentNode) {
            listLength++;
            if (listLength == k) {
                frontNode = currentNode;
            }
            currentNode = currentNode->next;
        }
        endNode = head;
        for (int i = 1; i <= listLength - k; i++) {
            endNode = endNode->next;
        }
        // swap front node and end node values
        swap(frontNode->val, endNode->val);
        return head;
    }
};