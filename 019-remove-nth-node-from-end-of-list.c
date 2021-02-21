#include "listnode.h"

#include <stdlib.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode fake = {.val = 0, .next = NULL}, *dummy = &fake, *p = dummy, *q = dummy;
    dummy->next = head;

    for (int i = 0; i < n + 1; i++)
    {
        q = q->next;
    }

    while (q != NULL)
    {
        p = p->next;
        q = q->next;
    }

    struct ListNode *del = p->next;
    p->next = del->next;
    free(del);

    return dummy->next;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    struct ListNode *head = createLinkedList(arr, n);
    printLinkedList(head);

    struct ListNode *newHead =  removeNthFromEnd(head, 2);
    printLinkedList(newHead);

    deleteLinkedList(newHead);

    return 0;
}
