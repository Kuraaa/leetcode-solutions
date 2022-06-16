#include "template.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> v;
        while (head != nullptr) {
            v.push_back(head);
            head = head->next;
        }
        return v[v.size() / 2];
    }

    ListNode* middleNodePointer(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};