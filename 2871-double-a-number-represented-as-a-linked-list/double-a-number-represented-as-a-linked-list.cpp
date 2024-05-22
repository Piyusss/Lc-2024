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
    ListNode* doubleIt(ListNode* head){
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;
        head=f(head);
        dummyNode->next=head;

        ListNode* temp=head;
        ListNode* prev=temp;
        int car=0;
        while(temp){
            int new_val=2*temp->val+car;
            temp->val=( new_val>=10 ? new_val-10 : new_val );
            if(new_val>=10)car=1;
            else car=0;
            prev=temp;
            temp=temp->next;
        }

        if(car==1){
            prev->next=new ListNode(1);
        }

        head=f(head);
        dummyNode->next=head;
        return dummyNode->next;
    }
};

//1 8 9
//9 8 1->reversed
//8 7 3->reverse it.

//3 7 8.->ans.