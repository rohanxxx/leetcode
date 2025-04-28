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
    struct compare {
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto l: lists){
            if(l) pq.push(l);
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!pq.empty()){
            ListNode* node = pq.top(); pq.pop();
            tail->next = node;
            if(node->next) 
                pq.push(node->next);
            tail = tail->next;
        }
        return dummy.next;
    }
};