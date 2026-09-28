class Solution {
public:
    int maxDepth(string s) {
        int n=s.size(),l_cnt=0,maxi=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(') l_cnt++;
            else if(s[i]==')') l_cnt--;
            maxi=max(maxi,l_cnt);
        }
        
        return maxi;
    }
};