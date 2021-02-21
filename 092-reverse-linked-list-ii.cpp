#include "LinkedList.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode node, *dummy = &node, *prev = dummy;
        dummy->next = head;

        for (int i = 0; i < m-1; i++) {
            prev = prev->next;
        }

        ListNode *start = prev->next;
        ListNode *then = start->next;

        for (int i = 0; i < n-m; i++) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }

        return dummy->next;
    }
};

#include <iostream>
using namespace std;

int main()
{
    int arr[]{1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createLinkedList(arr, n);
    printLinkedList(head);

    auto newHead = Solution().reverseBetween(head, 2, 4);
    printLinkedList(newHead);

    deleteLinkedList(newHead);

    return 0;
}
