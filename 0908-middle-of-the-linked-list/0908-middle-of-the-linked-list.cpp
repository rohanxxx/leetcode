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
    ListNode* middleNode(ListNode* head) {
        if(!head) return head;
        ListNode* temp = head;
        int count = 0, mid = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        if(count == 1) return head;
        mid = count/2;
        // cout << "mid: " << mid << endl;
        count = 0;
        while(head){
            count++;
            head = head->next;
            if(count == mid) return head;
        }
        return head;
    }
};