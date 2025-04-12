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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) return head;
        if(head == NULL) return NULL;
        
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        vector<ListNode*> arr(n);
        temp = head;
        for(int i = 0; i < n; i++){
            int index = (i+k) % n;
            arr[index] = temp;
            temp = temp->next;
        }
        for(int i = 0; i < n-1; i++){
            arr[i]->next = arr[i+1];
        }
        arr[n-1]->next = NULL;
        return arr[0];
    }
};