#include "LinkedList.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode fake, *dummy = &fake, *p = dummy, *q = dummy;
        dummy->next = head;

        for (int i = 0; i < n + 1; i++) {
            q = q->next;
        }

        while (q != nullptr) {
            p = p->next;
            q = q->next;
        }

        ListNode *del = p->next;
        p->next = del->next;
        delete del;
        
        return dummy->next;
    }
};

int main() {
    int arr[] {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    auto head = createLinkedList(arr, n);
    printLinkedList(head);

    auto newHead = Solution().removeNthFromEnd(head, 2);
    printLinkedList(newHead);

    deleteLinkedList(newHead);

    return 0;
}
