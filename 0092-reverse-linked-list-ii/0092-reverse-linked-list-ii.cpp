class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;

        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        ListNode* prev = NULL;
        ListNode* cur = head;

        for(int i = 1; i < left; i++){
            prev = cur;
            cur = cur->next;
        }

        ListNode* kPart = cur;
        for(int i = left; i < right; i++){
            cur = cur->next;
        }

        ListNode* rightSide = cur->next;
        cur->next = NULL;

        ListNode* reversedHead = rev(kPart);

        if(prev) prev->next = reversedHead;
        else head = reversedHead;

        cur = head;
        while(cur->next) cur = cur->next;
        cur->next = rightSide;

        return head;
    }
};