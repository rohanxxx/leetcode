/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seenNodes;
        ListNode* node = head;
        while(node){
            if(seenNodes.find(node) != seenNodes.end()) return node;
            seenNodes.insert(node);
            node = node->next;
        }
        return NULL;
    }
};