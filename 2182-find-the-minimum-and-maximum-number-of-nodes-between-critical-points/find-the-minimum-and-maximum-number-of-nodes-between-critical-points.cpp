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
        vector<int>temp;

        while(start->next){
            if((start->val<prev->val && start->val<start->next->val) || (start->val>prev->val && start->val>start->next->val)){
                temp.push_back(cnt);
                track++;
                if(temp.size()>=2)minDistance=min(minDistance,(temp[temp.size()-1]-temp[temp.size()-2]));
                maxi=max(maxi,cnt);
                mini=min(mini,cnt);
            }
            cnt++;
            prev=start;
            start=start->next;
        }

        if(track<=1)return {-1,-1};

        return {minDistance,maxi-mini};
    }
};