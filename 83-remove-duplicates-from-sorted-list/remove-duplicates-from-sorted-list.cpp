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
    ListNode* deleteDuplicates(ListNode* head){
        set<int>nodes_c;
        vector<int>nodes;

        ListNode* temp=head;

        while(temp){
            nodes_c.insert(temp->val);
            temp=temp->next;
        }

        for(auto &it:nodes_c) nodes.push_back(it);

        ListNode* dummyNode=new ListNode(-1);
        ListNode* dummyNodeMove=dummyNode;
        for(auto &it:nodes){
            dummyNodeMove->next=new ListNode(it);
            dummyNodeMove=dummyNodeMove->next;
        }

        return dummyNode->next;

    }
};