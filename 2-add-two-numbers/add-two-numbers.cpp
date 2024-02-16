class Solution {
public:
    ListNode* solve(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == nullptr && l2 == nullptr && carry == 0) {
            return nullptr;
        }
        int sum = 0;
        if (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1 != nullptr) {
            sum = l1->val + carry;
            l1 = l1->next;
        } else if (l2 != nullptr) {
            sum = l2->val + carry;
            l2 = l2->next;
        } else {
            sum = carry;
        }
        carry = sum / 10;
        ListNode* result = new ListNode(sum % 10);
        result->next = solve(l1, l2, carry);
        return result;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2, 0);
    }
};

   