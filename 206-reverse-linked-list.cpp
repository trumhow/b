#include "LinkedList.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main()
{
    int arr[]{1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createLinkedList(arr, n);
    printLinkedList(head);

    auto newHead = Solution().reverseList(head);
    printLinkedList(newHead);

    deleteLinkedList(newHead);

    return 0;
}
