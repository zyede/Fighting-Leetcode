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
        ListNode *tmp = newListNode;

        while (L1 && L2) {
            if (L1->val >= L2->val) {
                tmp->next = L2;
                L2 = L2->next;
            } else {
                tmp->next = L1;
                L1 = L1->next;
            }
            tmp = tmp->next;
        }
        L1?tmp->next=L1:tmp->next=L2;

        return newListNode->next;
    }
};