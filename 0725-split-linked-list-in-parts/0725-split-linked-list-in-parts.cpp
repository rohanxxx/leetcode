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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;

        int size = 0;
        while(temp) {
            temp = temp->next;
            size++;
        }

        int window = size / k;
        int extra = size % k;

        vector<ListNode*> ans;

        for(int i = 1; i <= k; i++) {
            int curWindow;
            if(extra > 0) {
                curWindow = window + 1;
                extra--;
            } else {
                curWindow = window;
            }

            ListNode* prev = NULL;
            ListNode* cur = head;

            int j = 1;
            while(cur && j <= curWindow) {
                prev = cur;
                cur = cur->next;
                j++;
            }

            if(prev != NULL) {
                prev->next = NULL;
            }

            ans.push_back(head);
            head = cur;
        }

        return ans;
    }
};