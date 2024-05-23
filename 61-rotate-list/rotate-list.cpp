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
    ListNode* rotateRight(ListNode* head, int k){
        if(!head || !head->next || k==0)return head;
        ListNode* len=head;
        int cnt=0;
        while(len){
            cnt++;
            len=len->next;
        }
        //

        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;

        ListNode* temp=dummyNode;
        while(k>cnt)k-=cnt;
        for(int i=1;i<=(cnt-k);i++)temp=temp->next;
        //

        ListNode* startNext=temp->next ? temp->next : NULL;
        temp->next=NULL;
        //

        ListNode* holdStartNext=startNext;
        while(startNext && startNext->next)startNext=startNext->next;
        startNext->next=dummyNode->next;
        //

        dummyNode->next=NULL;
        return holdStartNext;
    }
};