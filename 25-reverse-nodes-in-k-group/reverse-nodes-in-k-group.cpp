/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 * Solution {
public:
    ListNode *reverseLinkedList(ListNode *head){
        ListNode* current=head;
        ListNode* prev=NULL;
        while(current!=NULL){
            ListNode *temp=current->next;
           ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode *prev = NULL, *current = head, *temp;
        while (current != NULL) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head; // If the list is empty or k is 1, no need to reverse

        ListNode *temp = head, *prevLast = NULL;
        while (temp != NULL) {
            ListNode *kthNode = getKthNode(temp, k);
            if (kthNode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }

            ListNode *nextNode = kthNode->next;
            kthNode->next = NULL;
            ListNode *newHead = reverseLinkedList(temp);
            if (temp == head) {
                head = newHead;
            } else {
                prevLast->next = newHead;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
