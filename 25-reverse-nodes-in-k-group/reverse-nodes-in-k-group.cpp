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

ListNode* reverseFunc(ListNode* &head){
    if(!head || !head->next)return head;

    ListNode* newHead=reverseFunc(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

ListNode* findKthNode(ListNode* temp,int k){
    for(int i=1;i<=k-1 && temp;i++)temp=temp->next;
    return temp;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp){
            ListNode* kThNode=findKthNode(temp,k);
            if(kThNode==NULL){
                if(prevNode)prevNode->next=temp;
                break;
            }

            ListNode* nextOfKth=kThNode->next;
            kThNode->next=NULL;
            reverseFunc(temp);

            if(temp==head){
                head=kThNode;
            }
            else{
                prevNode->next=kThNode;
            }
            prevNode=temp;
            temp=nextOfKth;
        }

        return head;
    }
};