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
        if(head == NULL) return NULL;
        vector<ListNode*> v;
        while(head){
            v.push_back(head);
            head = head->next;
        }
        int n = v.size();
        for(int i = 0; i < n; i += 2){
            if(i+1 < n){
                swap(v[i], v[i+1]);
            }
        }
        for(int i = 1; i < n; i++){
            v[i-1]->next = v[i];
        }
        v.back()->next = NULL;
        return v[0];
    }
};