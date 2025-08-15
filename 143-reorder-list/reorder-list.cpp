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
private:
    ListNode *reverseList(ListNode *node){
        ListNode *prev=nullptr;
        while(node){
            ListNode *nxt=node->next;
            node->next=prev;
            prev=node;
            node=nxt;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *right=slow->next;
        slow->next=nullptr;
        right=reverseList(right);

        ListNode *left=head;
        while(right){
            ListNode *leftNext=left->next;
            ListNode *rightNext=right->next;

            left->next=right;
            right->next=leftNext;

            left=leftNext ? leftNext : right;
            right=rightNext;
        }
    }
};