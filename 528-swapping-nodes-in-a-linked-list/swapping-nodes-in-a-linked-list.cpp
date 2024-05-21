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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        if(!head->next)return head;
        
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }

        ListNode* start=head;
        int step_begin=1;
        while(step_begin<k){
            step_begin++;
            start=start->next;
        }

        ListNode* end=head;
        int step_end=1;
        while(step_end<cnt-k+1){
            step_end++;
            end=end->next;
        }

        int start_val=start->val;
        start->val=end->val;
        end->val=start_val;

        return head;
    }
};