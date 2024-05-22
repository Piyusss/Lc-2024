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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next)return NULL;

        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }



        int move=cnt-n;
        ListNode*dummyNode=new ListNode(-1);
        dummyNode->next=head;
        ListNode* temp2=dummyNode;
        
        for(int i=1;i<=move;i++)temp2=temp2->next;

        ListNode* temp3=temp2->next->next;
        temp2->next->next=NULL;
        temp2->next=temp3;

        return dummyNode->next;

    }
};