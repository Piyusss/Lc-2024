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

int mini=INT_MAX;
int maxi=INT_MIN;
int minDistance=INT_MAX;
int maxDistance=INT_MIN;

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==NULL)return {-1,-1};

        ListNode* start=head->next;
        ListNode* prev=head;
        int cnt=0;int track=0;
        int var1=-1,var2=-1;int flag=1;

        while(start->next){
            if((start->val<prev->val && start->val<start->next->val) || (start->val>prev->val && start->val>start->next->val)){
                if(flag)var1=cnt;
                else var2=cnt;
                track++;
                if(var1!=-1 && var2!=-1) minDistance=min(minDistance,abs(var1-var2));
                maxi=max(maxi,cnt);
                mini=min(mini,cnt);
                flag=!flag;
            }
            cnt++;
            prev=start;
            start=start->next;
        }

        if(track<=1)return {-1,-1};

        return {minDistance,maxi-mini};
    }
};