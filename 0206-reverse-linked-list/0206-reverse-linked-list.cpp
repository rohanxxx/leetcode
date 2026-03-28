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
    /*
         1 ->2 ->3 ->4 ->5
    */
    ListNode* reverseList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp);
            temp = temp->next;
        }
        int n = v.size();
        for(int i = n-1; i >= 0; i--){
            if(i == 0){
                v[i]->next = NULL;
                break;
            }
            v[i]->next = v[i-1];
        }
        if(n == 0){
            return NULL;
        }
        return v[n-1];
    }
};