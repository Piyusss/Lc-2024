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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* dummyy=dummy;

        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;

        
        while(temp1 || temp2){
            int v=carry;
            if(temp1)v+=temp1->val;
            if(temp2)v+=temp2->val;

            dummyy->next=new ListNode(v%10);
            carry=v/10;
            dummyy=dummyy->next;

            if(temp1)temp1=temp1->next;
            if(temp2)temp2=temp2->next;
        }

        if(carry)dummyy->next=new ListNode(1);
        return dummy->next;
    }
};