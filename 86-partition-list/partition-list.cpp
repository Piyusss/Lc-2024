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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyNode1=new ListNode(-1);
        ListNode* dummyNode11=dummyNode1;

        ListNode* dummyNode2=new ListNode(-1);
        ListNode* dummyNode22=dummyNode2;

        while(head){
            if(head->val<x){
                dummyNode1->next=head;
                dummyNode1=dummyNode1->next;
            }
            else{
                dummyNode2->next=head;
                dummyNode2=dummyNode2->next;
            }
            head=head->next;
        }

        dummyNode1->next=NULL;
        dummyNode2->next=NULL;
        dummyNode1->next=dummyNode22->next;

        return dummyNode11->next;
    }
};