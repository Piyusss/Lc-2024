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
ListNode* f(ListNode* head){
    if(head==NULL || head->next==NULL)return head;
    ListNode* last=f(head->next);
    head->next->next=head;
    head->next=NULL;
    return last;
}
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rev=f(slow);
        ListNode* curr=head;

        while(rev->next!=NULL){
            ListNode* tempCurr=curr->next;
            curr->next=rev;

            ListNode* tempRev=rev->next;
            rev->next=tempCurr;

            curr=tempCurr;
            rev=tempRev;
        }
    }
};