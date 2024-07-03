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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(0);
        ListNode* temp = sum;
        int carry = 0;
        while(l1 || l2){
            int add = carry;
            if(l1){
                add += l1->val;
                l1 = l1->next;
            }

            if(l2){
                add += l2->val;
                l2 = l2->next;
            }

            carry = add/10;
            add = add%10;

            temp->next = new ListNode(add);
            temp = temp->next;
        }

        if(carry) temp->next = new ListNode(carry);
        return sum->next;
    }
};