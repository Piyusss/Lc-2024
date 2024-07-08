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
        int cnt=0;

        if(head->next==NULL)return NULL;

        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }

        int move=cnt-n-1;
        //if move is negative then we have to remove the first node.
        if(move<0){
            ListNode* wait=head->next;
            head->next=NULL;
            delete(head);
            return wait;
        }

        //place temp2 in appropriate position
        ListNode* temp2=head;
        for(int i=1;i<=move;i++)temp2=temp2->next;

        ListNode* wait=temp2->next;
        temp2->next=temp2->next->next ? temp2->next->next: NULL;
        wait->next=NULL;
        delete(wait);

        return head;
    }
};