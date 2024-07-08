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
    ListNode *detectCycle(ListNode *head) {
        if(!head)return 0;
        ListNode* slow=head;
        ListNode* fast=head;

        int cnt=0;
        while(fast && fast->next){
            cnt++;
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)break;
        }

        if(cnt && slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }

        return NULL;
    }
};