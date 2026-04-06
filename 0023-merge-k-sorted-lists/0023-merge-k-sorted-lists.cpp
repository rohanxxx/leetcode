class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amount = lists.size();
        int interval = 1;

        while (interval < amount) {
            for (int i = 0; i < amount - interval; i += interval * 2) {
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            }
            interval = interval * 2;
        }

        if (amount > 0) {
            return lists[0];
        } else {
            return NULL;
        }
    }

private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* point = &head;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                point->next = l1;
                l1 = l1->next;
            } else {
                point->next = l2;
                l2 = l2->next;
            }
            point = point->next;
        }

        if (l1 == NULL) {
            point->next = l2;
        } else {
            point->next = l1;
        }

        return head.next;
    }
};