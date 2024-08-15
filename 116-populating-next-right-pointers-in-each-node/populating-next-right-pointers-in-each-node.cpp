/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;

        Node* cur=root;

        while(cur->left){
            Node* temp=cur;
            while(cur){
                cur->left->next=cur->right;
                cur->right->next=cur->next!=NULL ? cur->next->left : NULL;
                cur=cur->next;
            }
            cur=temp->left;
        }
        
        return root;
    }
};