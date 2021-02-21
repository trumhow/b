#include "LinkedList.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        head->next = deleteDuplicates(head->next);
        if (head->val != head->next->val) return head;
        ListNode* ret = head->next;
        delete head;
        return ret;
    }
};

int main()
{
    int arr[]{1, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createLinkedList(arr, n);
    printLinkedList(head);

    ListNode *newHead = Solution().deleteDuplicates(head);
    printLinkedList(newHead);

    deleteLinkedList(newHead);

    return 0;
}
