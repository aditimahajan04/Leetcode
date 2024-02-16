class Solution {
public:
    ListNode* solve(ListNode* list1, ListNode* list2) {
       if(list1==nullptr)
       {
           return list2;
       }
       if(list2==nullptr)
       {
           return list1;
       }
       if(list1->val<=list2->val)
       {
           list1->next= solve(list1->next,list2);
           return list1;
        } else {
            list2->next = solve(list1, list2->next);
            return list2;
        }

    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return solve(l1, l2);
    }
};
