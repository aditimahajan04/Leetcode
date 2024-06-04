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
class cmp{
    public:
    bool operator()(const ListNode *a,const ListNode *b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        priority_queue<ListNode*,vector<ListNode*>,cmp> minHeap;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL){
                minHeap.push(lists[i]);
            }
        }
        while(!minHeap.empty()){
            auto lowest=minHeap.top();
            minHeap.pop();
            temp->next=lowest;
            temp=temp->next;
            if(lowest->next){
                minHeap.push(lowest->next);
            }
        }
        return head->next;
    }
};