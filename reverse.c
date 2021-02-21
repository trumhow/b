#include "listnode.h"

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    struct ListNode node = {0, NULL}, *dummy = &node, *prev = dummy;
    dummy->next = head;

    for (int i = 0; i < m-1; i++)
    {
        prev = prev->next;
    }

    struct ListNode *start = prev->next, *then = start->next;

    for (int i = 0; i < n-m; i++)
    {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy->next;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createLinkedList(arr, n);
    printLinkedList(head);

    ListNode *newHead = reverseBetween(head, 2, 4);
    printLinkedList(newHead);

    deleteLinkedList(newHead);

    return 0;
}
