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

    ListNode* removeNodes(ListNode* head){

        head=f(head);
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;

        ListNode* temp=head;
        ListNode* prev=temp;
        int maxi=INT_MIN;
        while(temp){
            if(maxi<=temp->val){
                maxi=temp->val;
                prev=temp;
                temp=temp->next;
            }
            else{
                ListNode* temp2=temp->next;
                prev->next=temp2;
                temp->next=NULL;
                temp=temp2;
            }
        }
        head=f(head);
        dummyNode->next=head;
        return dummyNode->next;
    }
};
//5 2 13 3 8

//8 3 13 2 5

//8 13
//13 8.

//5 2 13 5 8
//8 5 13 2 5
//8 13
//13 8