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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt==1)return NULL;
        //now

        ListNode* flag=head;
        ListNode* before=flag;
        int flagCnt=0;int mid=cnt/2;
        while(flagCnt!=mid){
            flagCnt++;
            before=flag;
            flag=flag->next;
        }
        //now 7 pe flag hai
        before->next=flag->next;
        flag->next=NULL;
        return head;

    }
};