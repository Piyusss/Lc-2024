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
    ListNode* removeZeroSumSublists(ListNode* head) {

        int prefixSum=0;
        map<int,ListNode*>mp;

        ListNode* temp=head;
        ListNode* dummyNode=new ListNode(-1001);dummyNode->next=head;mp[0]=dummyNode;
        while(temp){
            prefixSum+=temp->val;

            if(mp[prefixSum]){
                ListNode* tempInside=mp[prefixSum]->next;
                //delete entries from tempInside to temp
                int pSum=prefixSum;

                while(tempInside!=temp){
                    pSum+=tempInside->val;
                    mp.erase(pSum);
                    tempInside=tempInside->next;
                }

                mp[prefixSum]->next=temp->next;
            }
            if(!mp[prefixSum]){
                mp[prefixSum]=temp;
            }
            temp=temp->next;
        }
        
        return dummyNode->next;
    }
};