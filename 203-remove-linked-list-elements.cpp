#include "LinkedList.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode node, *dummy{ &node }, *cur{ dummy };
        dummy->next = head;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode *del{ cur->next };
                cur->next = del->next;
                delete del;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

int main()
{
    int arr[]{1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createLinkedList(arr, n);
    printLinkedList(head);

    auto newHead = Solution().removeElements(head, 1);
    printLinkedList(newHead);

    deleteLinkedList(newHead);

    return 0;
}
