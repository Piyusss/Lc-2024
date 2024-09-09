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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        ListNode* temp=head;
        vector<int>v;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }

        int left=0,top=0,bottom=n-1,right=m-1;
        vector<vector<int>>ans(n,vector<int>(m,-1));
        int mark=0;

        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                if(mark<v.size()) ans[top][i]=(v[mark++]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                if(mark<v.size()) ans[i][right]=(v[mark++]);
            }
            right--;

            //now

            if(top<=bottom){
                for(int i=right;i>=left;i--){
                if(mark<v.size()) ans[bottom][i]=(v[mark++]);
            }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                if(mark<v.size()) ans[i][left]=(v[mark++]);
            }
                left++;
            }
        }

        return ans;

    }
};