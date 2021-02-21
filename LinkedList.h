#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>

struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
};

ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode *head = new ListNode(arr[0]), *cur = head;
    for (int i = 1; i < n; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode *cur = head;
    while (cur != nullptr) {
        std::cout << cur->val << " -> ";
        cur = cur->next;
    }
    std::cout << "null" << std::endl;
}

void deleteLinkedList(ListNode* head) {
    ListNode *cur = head;
    while (cur != nullptr) {
        ListNode *del = cur;
        cur = cur->next;
        delete del;
    }
}


#endif // __LINKED_LIST_H__
