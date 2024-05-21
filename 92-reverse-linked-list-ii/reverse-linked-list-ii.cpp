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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next)return head;

        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;

        ListNode* prev=dummyNode;
        for(int i=1;i<left;i++){
            prev=prev->next;
        }

        ListNode* cur=prev->next;

        for(int i=1;i<=right-left;i++){
            ListNode* temp=prev->next;
            prev->next=cur->next;
            cur->next=cur->next->next;
            prev->next->next=temp;
        }

        return dummyNode->next;
    }
};