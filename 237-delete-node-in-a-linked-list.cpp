#include "LinkedList.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr) return;
        if (node->next == nullptr) {
            delete node;
            node = nullptr;
        }

        node->val = node->next->val;
        ListNode *del = node->next;
        node->next = del->next;
        delete del;
    }
};

int main() {
    int arr[] {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    auto head = createLinkedList(arr, n);
    printLinkedList(head);

    auto p = head;
    for (int i = 0; i < 3; i++) {
        p = p->next;
    }

    Solution().deleteNode(p);
    printLinkedList(head);

    deleteLinkedList(head);

    return 0;
}
