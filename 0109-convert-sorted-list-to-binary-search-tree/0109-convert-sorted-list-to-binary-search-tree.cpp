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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //sets the initial case
        if(!head) return NULL;
        
        ListNode* prev = NULL;
        ListNode* mid = head;
        ListNode* fast = head;

        while(fast && fast->next){
            prev = mid;
            mid = mid->next;
            fast = fast->next->next; 
        }

        if(prev) prev->next = NULL;

        TreeNode* node = new TreeNode(mid->val);

        //sets the initialcase
        if(head == mid) return node;

        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid->next);

        return node;
    }
};