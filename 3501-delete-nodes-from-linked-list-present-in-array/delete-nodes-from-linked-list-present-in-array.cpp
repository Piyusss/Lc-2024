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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto &it:nums)st.insert(it);

        vector<int>res;
        ListNode* temp=head;
        while(temp){
            if(st.find(temp->val)==st.end())res.push_back(temp->val);
            temp=temp->next;
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* dummyCopy=dummy;

        for(auto &it:res){
            dummyCopy->next=new ListNode(it);
            dummyCopy=dummyCopy->next;
        }

        return dummy->next;

    }
};