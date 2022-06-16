#include "template.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* sort;
        while (list1->next && list2->next) {
            if (list1->val < list2->val) {
                list1->next = list2;
            }
            list2->next;
        }
        return list1;
    }
};