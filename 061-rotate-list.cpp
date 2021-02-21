#include "LinkedList.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode fake, *dummy{ &fake }, *p{ dummy }, *q{ dummy }, *c{ head };
        dummy->next = head;

        int count = 0;
        while (c != nullptr) {
            count++;
            c = c->next;
        }
        if (count == 0) return nullptr;
        if ((k %= count) == 0) return head;

        for (int i = 0; i < k; i++) {
            q = q->next;
        }
        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }

        ListNode *ret = p->next;
        p->next = nullptr;
        q->next = head;

        return ret;
    }
};

#include <iostream>
using namespace std;

int main() {
    int arr[] {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    auto head = createLinkedList(arr, n);
    printLinkedList(head);

    auto newHead = Solution().rotateRight(head, 2);
    printLinkedList(newHead);

    deleteLinkedList(newHead);

    return 0;
}
