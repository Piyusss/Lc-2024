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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

vector<vector<int>>ans;
vector<int>v;

void f(TreeNode* root){
    if(!root)return;

    v.push_back(root->val);

    f(root->left);
    f(root->right);

    if(!root->left && !root->right) ans.push_back(v);
    v.pop_back();

    return;

}
    bool isSubPath(ListNode* head, TreeNode* root){
        f(root);

        string haveToBeFound="";
        ListNode* ok=head;
        while(ok){
            haveToBeFound+=to_string(ok->val);
            ok=ok->next;
        }
        cout<<haveToBeFound<<endl;

        for(int i=0;i<ans.size();i++){
            vector<int>temp=ans[i];
            string st="";
            for(auto &it:temp)st+=to_string(it);
            if(st.find(haveToBeFound)!=std::string::npos)return 1;
        }

        return 0;

    }
};