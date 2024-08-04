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
        int cnt=1;
        while(len->next){
            cnt++;
            len=len->next;
        }
        if(k%cnt==0)return head;

        len->next=head;
        ListNode* temp=head;
        k=k%cnt;
        for(int i=1;i<=(cnt-k)-1;i++)temp=temp->next;

        head=temp->next ;
        temp->next=NULL;
        return head;
    }
};