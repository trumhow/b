#include "listnode.h"

#include <stdlib.h>

void deleteNode(struct ListNode* node)
{    
    if (node == NULL) return;
    if (node->next == NULL)
    {
        free(node);
        node = NULL;
    }

    node->val = node->next->val;
    struct ListNode *del = node->next;
    node->next = del->next;
    free(del);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    struct ListNode *head = createLinkedList(arr, n);
    printLinkedList(head);

    struct ListNode *p = head;
    for (int i = 0; i < 3; i++)
    {
        p = p->next;
    }

    deleteNode(p);
    printLinkedList(head);

    deleteLinkedList(head);

    return 0;
}
