/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        int flag1=0,flag2=0;
        while(temp1 || temp2){
            if(temp1==temp2)return temp1;

            if(!temp1 && flag1==0){
                temp1=headB;
                flag1=1;
                temp2=temp2->next;
                continue;
            }
            if(!temp2 && flag2==0){
                temp2=headA;
                flag2=1;
                temp1=temp1->next;
                continue;
            }

            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};