/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp){
            Node* newMidNode=new Node(temp->val);
            newMidNode->next=temp->next;
            temp->next=newMidNode;

            temp=temp->next->next;
        }




        Node* temp1=head;
        while(temp1){
            temp1->next->random=temp1->random ? temp1->random->next : NULL;

            temp1=temp1->next->next;
        }


        Node* temp2=head;
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        while(temp2){
            res->next=temp2->next;
            res=res->next;
            temp2->next=temp2->next->next;

            temp2=temp2->next;
        }
        return dummyNode->next;
    }
};