#include "LinkedList.h"
// #include "001-two-sum.cpp"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode fake, *dummy = &fake, *prev = dummy;
        bool carry = false;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (carry) {
                sum += 1;
                carry = false;
            }
            if (sum >= 10) carry = true;

            auto node = new ListNode(sum % 10);

            prev->next = node;
            prev = node;
        }
        if (carry) {
            auto node = new ListNode(1);
            prev->next = node;
        }
        return dummy->next;
    }
};

int main() {
    int arr1[]{2, 4, 3};
    int arr2[]{5, 6, 4};
    auto l1 = createLinkedList(arr1, 3);
    auto l2 = createLinkedList(arr2, 3);
    printLinkedList(l1);
    printLinkedList(l2);

    auto ans = Solution().addTwoNumbers(l1, l2);
    printLinkedList(ans);

    deleteLinkedList(l1);
    deleteLinkedList(l2);
    deleteLinkedList(ans);

    return 0;
}
