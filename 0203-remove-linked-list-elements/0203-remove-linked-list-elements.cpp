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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        queue<ListNode*> q;
        ListNode* temp = head;
        while(temp){
            if(temp->val != val){
                // cout << "temp->val: " << temp ->val << endl;
                q.push(temp);
            }
            temp = temp->next;
        }
        if(q.empty()) return NULL;
        head = q.front();
        ListNode* cur;
        while(!q.empty()){
            cur = q.front(); q.pop();
            if(!q.empty()){
                cur->next = q.front();
            }
        }
        cur->next = NULL;
        return head;
    }
};