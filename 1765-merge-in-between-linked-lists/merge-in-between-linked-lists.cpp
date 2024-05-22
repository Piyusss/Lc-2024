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
    ListNode* mergeInBetween(ListNode* h1, int a, int b, ListNode* h2) {
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=h1;
        int cnt=0;
        ListNode* temp=h1;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        //now

        ListNode* temp2=dummyNode;
        for(int i=1;i<=b+1;i++)temp2=temp2->next;
        
        ListNode* lastConnect=temp2->next;

        ListNode* temp1=dummyNode;
        for(int i=1;i<=a;i++)temp1=temp1->next;


        //now
        temp1->next=h2;
        //now


        ListNode* templ2=h2;
        while(templ2->next){
            templ2=templ2->next;
        }

        //now
        templ2->next=lastConnect;


        return dummyNode->next;
    }
};