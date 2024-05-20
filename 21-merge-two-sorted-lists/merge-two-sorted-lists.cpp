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
        ListNode* flag=new ListNode(ans[i]);
        temp->next=flag;
        temp=temp->next;
    }
    return start;
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        vector<int>ans;
        f(ans,list1);
        f(ans,list2);
        sort(ans.begin(),ans.end());
        if(ans.size()==0)return NULL;

        return func(ans);
    }
};