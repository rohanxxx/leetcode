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
     1->1->2->3->4->4->5->6
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(ListNode* list: lists){
            pq.push({list->val, list});
        }

        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(!pq.empty()){
            ListNode* top = pq.top().second; pq.pop();
            temp->next = top;
            temp = temp->next;
        }

        return head->next;
    }
};