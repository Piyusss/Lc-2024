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
void f(vector<int>&ans,ListNode* list){
    ListNode* temp=list;
    while(temp!=NULL){
        ans.push_back(temp->val);
        temp=temp->next;
    }
}

ListNode* func(vector<int>ans){
    ListNode* temp=new ListNode(ans[0]);
    ListNode* start=temp;
    for(int i=1;i<ans.size();i++){
        temp->next=new ListNode(ans[i]);
        temp=temp->next;
    }
    return start;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>ans;
        for(auto it:lists){
            f(ans,it);
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0)return NULL;

        return func(ans);
    }
};