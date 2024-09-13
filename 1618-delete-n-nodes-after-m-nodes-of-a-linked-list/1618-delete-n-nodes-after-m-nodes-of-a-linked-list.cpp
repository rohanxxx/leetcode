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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* currentNode = head;
        ListNode* lastMNode = head;

        while(currentNode){
            int mCount = m, nCount = n;
            while(currentNode && mCount){
                lastMNode = currentNode;
                currentNode = currentNode->next;
                mCount--;
            }

            while(currentNode && nCount){
                currentNode = currentNode->next;
                nCount--;
            }

            lastMNode->next = currentNode;
        }
        return head;
    }
};