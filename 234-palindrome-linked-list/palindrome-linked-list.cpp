/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseLinkedList(ListNode *head){
        if(head==NULL || head->next ==NULL){
            return head;
        }
        ListNode *newHead=reverseLinkedList(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        // Move slow to the middle and fast to the end
        while(fast->next !=NULL && fast->next->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // Reverse the second half of the linked list
        ListNode *newHead=reverseLinkedList(slow->next);
        ListNode *first=head;
        ListNode *second=newHead;
        bool palindrome = true;
        // Check if the linked list is a palindrome
        while(second !=NULL){
            if(first->val != second->val){
                palindrome = false;
                break;
            }
            first=first->next;
            second=second->next;
        }

        // Restore the original linked list structure
        slow->next=reverseLinkedList(newHead);
        return palindrome;
    }
};
