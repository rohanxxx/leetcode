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
    vector<ListNode*> lists;
    int listSize;
public:
    //TC: O(1e4)
    //SC: O(1e4)
    Solution(ListNode* head) {
        srand(time(0));
        ListNode* temp = head;
        while(temp){
            lists.push_back(temp);
            temp = temp->next;
        }
        listSize = lists.size();
    }
    
    //TC: O(1)
    int getRandom() {
        int randomIndex = rand() % listSize;
        return lists[randomIndex]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */