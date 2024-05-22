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


    bool isPalindrome(ListNode* frwd){

        ListNode* wait=new ListNode(-1);
        ListNode* wait3=wait;
        ListNode* wait1=frwd;
        while(wait1){
            wait->next=new ListNode(wait1->val);
            wait1=wait1->next;
            wait=wait->next;
        }
        ListNode* wait2=wait3->next;
        wait->next=NULL;
        ListNode* rev=f(wait2);

        ListNode* temp1=frwd;
        ListNode* temp2=rev;

        while(temp1 && temp2){
            if(temp1->val!=temp2->val)return 0;
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return 1;
    }
};