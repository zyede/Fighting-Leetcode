#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *L1, ListNode *L2) {
        if (!L1 && !L2) return NULL;
        if (!L1) return L2;
        if (!L2) return L1;

        ListNode *newListNode = new ListNode(0);

        if (L1->val >= L2->val) {
            newListNode->val = L2->val;
            new
        }

    }
};