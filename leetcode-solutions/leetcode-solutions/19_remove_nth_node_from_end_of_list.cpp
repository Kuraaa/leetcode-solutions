#include "template.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0, head);
        ListNode* left = &dummy;
        ListNode* right = head;

        while (n > 0 && right) {
            right = right->next;
            n--;
        }

        while (right) {
            right = right->next;
            left = left->next;
        }

        left->next = left->next->next;
        return dummy.next;
    }
};