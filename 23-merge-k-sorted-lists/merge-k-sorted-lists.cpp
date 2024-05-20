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
ListNode* f(ListNode* head1,ListNode* head2){
        ListNode* temp1=head1;
        ListNode* temp2=head2;

        ListNode* dummyNode=new ListNode(-1);
        ListNode* dummyNodePrev=dummyNode;

        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                dummyNode->next=temp1;
                dummyNode=temp1;
                temp1=temp1->next;
            }
            else{
                dummyNode->next=temp2;
                dummyNode=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1)dummyNode->next=temp1;
        if(temp2)dummyNode->next=temp2;
        return dummyNodePrev->next;
}
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size()==0)return NULL;

        ListNode* temp1=lists[0];
        for(int i=1;i<lists.size();i++){
            ListNode* temp2=lists[i];
            temp1=f(temp1,temp2);
        }

        return temp1;
    }
};