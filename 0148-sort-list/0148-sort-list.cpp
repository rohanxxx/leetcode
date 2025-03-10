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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummyHead = new ListNode(0);
        ListNode* ptr = dummyHead;
        while(left && right){
            if(left->val < right->val){
                ptr->next = left;
                left = left->next;
            }
            else{
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        if(left) ptr->next = left;
        else ptr->next = right;
        
        return dummyHead->next;
    }
    ListNode* getMid(ListNode* head){
        ListNode* midPrev = NULL;
        while(head && head->next){
            if(midPrev == NULL) midPrev = head;
            else midPrev = midPrev->next;
            head = head->next->next;
        }

        ListNode* mid = midPrev->next;
        midPrev->next = NULL;
        return mid;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
};