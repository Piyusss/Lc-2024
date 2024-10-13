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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;

        unordered_map<int,int>mp;

        ListNode* temp=head;
        while(temp){
            mp[temp->val]++;
            temp=temp->next;
        }

        set<int>els;
        for(auto &it:mp){
            if(it.second==1) els.insert(it.first);
        }

        ListNode* dummyNode=new ListNode(-1);
        ListNode* moveDummy=dummyNode;

        for(auto &it:els){
            moveDummy->next=new ListNode(it);
            moveDummy=moveDummy->next;
        }

        return dummyNode->next;

    }
};