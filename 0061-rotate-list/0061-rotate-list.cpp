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

 /*                0 1 2 3 4
    Input: head = [1,2,3,4,5], k = 2
    Output:       [4,5,1,2,3]

    vector<ListNode*> store
    vector<ListNode*> newVector
    (index+k)%n  
    0+2/5 -> 2
    3/5 -> 3
    4/5 -> 4
    5/5 -> 0
    
    5-2->3
    0 1 2 3
    1 2 3 4 5 
    |-------|

    4 as our new head

    newHeadIndex => n-(k%n);
    

 */
class Solution {
public:
    //TC: O(N)
    //SC: O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        //TC: O(N)
        //step#1 make the list circular
        int n = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            n++;
            prev = curr;
            curr = curr->next;
        }

        if(n == 1){
            return head;
        }

        //edge case
        if(prev == NULL){
            return NULL;
        }

        //otherwise connect 
        //now the head is circular
        prev->next = head;

        curr = head;
        prev = NULL;

        int index = 0;
        int newHeadIndex = n - (k%n);
        //TC: O(N)
        while(index < newHeadIndex && curr){
            prev = curr;
            curr = curr->next;
            index++;
        }

        //detaches the circular property
        prev->next = NULL;

        return curr;
    }
};