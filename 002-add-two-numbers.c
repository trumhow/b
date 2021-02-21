#include <stdlib.h>
#include <stdbool.h>
#include "listnode.h"

// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode fake = {.val = 0, .next = NULL}, *dummy = &fake, *prev = dummy;
    bool carry = false;
    while (l1 != NULL || l2 != NULL)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        if (carry)
        {
            sum += 1;
            carry = false;
        }
        if (sum >= 10) carry = true;

        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;

        prev->next = node;
        prev = node;
    }
    if (carry)
    {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = 1;
        node->next = NULL;
        prev->next = node;
    }
    return dummy->next;
}

int main()
{
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode *l1 = createLinkedList(arr1, 3);
    ListNode *l2 = createLinkedList(arr2, 3);
    printLinkedList(l1);
    printLinkedList(l2);

    ListNode *ans = addTwoNumbers(l1, l2);
    printLinkedList(ans);

    deleteLinkedList(l1);
    deleteLinkedList(l2);
    deleteLinkedList(ans);

    return 0;
}
