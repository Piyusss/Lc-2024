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
ListNode* TortoiseAndHare(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* callMergeFunction(ListNode* left,ListNode* right){
    ListNode* dummyNode=new ListNode(-1);
    ListNode* temp=dummyNode;
    while(left && right){
        if(left->val<right->val){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    if(left)temp->next=left;
    else temp->next=right;
    return dummyNode->next;
}
ListNode* mergeFunction(ListNode* head){
    if(!head || !head->next)return head;

    ListNode* mid=TortoiseAndHare(head);
    ListNode* right=mid->next;
    mid->next=NULL;
    ListNode* left=head;

    left=mergeFunction(left);
    right=mergeFunction(right);
    return callMergeFunction(left,right);
}

    ListNode* sortList(ListNode* head) {
        return mergeFunction(head);
    }
};