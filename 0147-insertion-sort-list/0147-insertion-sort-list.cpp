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
    ListNode* getTheNode(ListNode* it, ListNode* start){
        ListNode* prev = start;
        while(it){
            if(it->val < prev->val){
                prev->next = it->next;
                it->next = NULL;
                break;
            }
            prev = it;
            it = it->next;
        }

        return it;
    }

    void sortNode(ListNode* node, ListNode* start){
        ListNode* it = start;
        ListNode* prev = start;
        while(it && node->val > it->val){
            prev = it;
            it = it->next;
        }
        node->next = it;
        prev->next = node;
    }

    ListNode* insertionSortList(ListNode* head) {
        ListNode* start = new ListNode(-5001);
        start->next = head;

        ListNode* it = start->next;
        ListNode* node = getTheNode(it, start);
        while(node){
            sortNode(node, start);
            it = node->next; // resume scanning right after where node was reinserted... but see note below
            node = getTheNode(it, start);
        }

        return start->next;
    }
};