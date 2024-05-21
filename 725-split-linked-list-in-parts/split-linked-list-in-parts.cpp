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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }

        int eachCap=cnt/k;
        int remNodes=cnt%k;

        vector<ListNode*>ans(k,NULL);
        ListNode* prev=NULL;
        ListNode* cur=head;

        for(int i=0;i<k && cur!=NULL;i++){
            for(int count=1;count<=eachCap+(remNodes>0?1:0);count++){
                prev=cur;
                cur=cur->next;
            }
            prev->next=NULL;
            ans[i]=head;
            head=cur;
            remNodes--;
        }
        return ans;
    }
};