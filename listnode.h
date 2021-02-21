#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode* createLinkedList(int arr[], int n)
{
    if (n == 0) return NULL;
    ListNode *head = (ListNode *)malloc(sizeof(ListNode)), *cur = head;
    head->val = arr[0];
    for (int i = 1; i < n; i++)
    {
        cur->next = (ListNode *)malloc(sizeof(ListNode));
        cur->next->val = arr[i];
        cur = cur->next;
    }
    return head;
}

void printLinkedList(ListNode* head)
{
    ListNode *cur = head;
    while (cur != NULL)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("null\n");
}

void deleteLinkedList(ListNode* head)
{
    ListNode *cur = head;
    while (cur != NULL)
    {
        ListNode *del = cur;
        cur = cur->next;
        free(del);
    }
}

#endif // __LIST_NODE_H__
