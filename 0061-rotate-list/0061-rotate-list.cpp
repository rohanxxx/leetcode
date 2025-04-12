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
        int i = 0;
        temp = head;
        // cout << "temp->val: " << temp->val << endl;
        while(temp){
            int index = (i+k) % n;
            // if(temp == NULL) cout << "line 25" << endl;
            arr[index] = temp;
            // cout << "index: " << index;
            // cout << " arr[index]: " << arr[index]->val << endl;
            temp = temp->next;
            i++;
        }
        for(int j = 0; j < n-1; j++){
            // cout << arr[j]->val << " ";
            arr[j]->next = arr[j+1];
        }
        // cout << endl;
        arr[n-1]->next = NULL;

        return arr[0];
    }
};