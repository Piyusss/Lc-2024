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

ListNode* f(ListNode* &head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    while(curr!=NULL){
        ListNode* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

    int pairSum(ListNode* head){
        int cnt=0;

        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }

        ListNode* temp2=head;
        int cnt2=1;
        while(cnt2!=cnt/2){
            temp2=temp2->next;
            cnt2++;
        }

        ListNode* start= cnt&1 ? temp2->next->next : temp2->next;
        temp2->next=NULL;

        ListNode* reversedPart=f(start);

        //now
        ListNode* flag1=head;
        ListNode* flag2=reversedPart;
        int maxi=INT_MIN;
        
        for(int i=0;i<cnt/2;i++){
            maxi=max(maxi,flag1->val+flag2->val);
            flag1=flag1->next;
            flag2=flag2->next;
        }
        return maxi;
    }
};