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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        int temp = head->val;
        ListNode* tempHead = head->next;
        ListNode* prev = head;
        while(tempHead != NULL){
            if(tempHead->val != temp){
                temp = tempHead->val;
                prev = tempHead;
                tempHead = tempHead->next;
            }
            else{
                prev->next = tempHead->next;
                tempHead = prev->next;
            }
        }

        return head;
    }
};