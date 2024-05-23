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
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        map<ListNode*,bool>mp;
        ListNode* temp1=h1;
        ListNode* temp2=h2;

        while(temp1){
            mp[temp1]=1;
            temp1=temp1->next;
        }

        while(temp2){
            if(mp[temp2]==1)return temp2;
            temp2=temp2->next;
        }

        return NULL;
    }
};