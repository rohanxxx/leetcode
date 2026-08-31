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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        int left = INT_MAX;
        int right = INT_MIN;

        int minDis = INT_MAX;
        int maxDis = INT_MIN;

        int i = 0;
        int prev_i = -1;
        while(curr){
            //check the critical point
            //prev node and next node exists
            if(prev && curr->next){
                //checks for local minimum and maximum
                if((prev->val < curr->val && curr->val > curr->next->val) || (prev->val > curr->val && curr->val < curr->next->val)){
                    left = min(left, i);
                    right = max(right, i);
                    //keep check the minDis
                    if(prev_i != -1){
                        minDis = min(minDis, i-prev_i);
                    }
                    prev_i = i;
                }
            }
            prev = curr;
            curr = curr->next;
            i++;
        }

        if(left == INT_MAX || right == INT_MIN || right-left <= 0){
            maxDis = -1;
        }
        else{
            maxDis = right-left;
        }

        if(prev_i == -1 || minDis == INT_MAX){
            minDis = -1;
        }

        return {minDis, maxDis};
    }
};