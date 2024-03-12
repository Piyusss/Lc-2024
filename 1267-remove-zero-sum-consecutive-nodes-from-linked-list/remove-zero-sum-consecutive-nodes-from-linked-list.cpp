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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == nullptr)
        return head;

    ListNode* current = head;
    int sum = 0;

    while (current != nullptr) {
        sum += current->val;
        if (sum == 0) {
            head = current->next;
            return removeZeroSumSublists(head);
        }
        current = current->next;
    }

    head->next = removeZeroSumSublists(head->next);
    return head;
    }
};