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
    //TC: O(N+N/2+N/2) = O(2N) = O(N)
    int pairSum(ListNode* head) {
        int listSize = 0;
        ListNode* temp = head;

        //TC: O(N)
        while(temp){
            temp = temp->next;
            listSize++;
        }

        //TC: O(1)
        if(listSize == 2){
            return head->val + head->next->val;
        }
        
        ListNode* cur = head;
        ListNode* nextPtr = cur->next;
        ListNode* prev = NULL;

        //TC: O(N/2)
        for(int i = 0; i < listSize/2; i++){
            //reverse the firsthalf
            cur->next = prev;
            prev = cur;
            cur = nextPtr;
            nextPtr = nextPtr->next;
        }

        int maxSum = INT_MIN;
        //TC: O(N/2)
        while(prev && cur){
            maxSum = max(maxSum, prev->val+cur->val);
            prev = prev->next;
            cur = cur->next;
        }

        return maxSum;
    }
};