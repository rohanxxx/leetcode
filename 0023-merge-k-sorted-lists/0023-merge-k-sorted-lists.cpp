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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> temp;
        for(ListNode* l: lists){
            while(l){
                temp.push_back(l->val);
                l = l->next;
            }
        }

        sort(temp.begin(), temp.end());

        ListNode* head = new ListNode(0);
        ListNode* t = head;
        for(int n: temp){
            t->next = new ListNode(n);
            t = t->next;
        }

        return head->next;
    }
};