class Solution {
public:

    int dp[101][101];

    bool f(int idx,int open,string &s,int n){
        if(idx==n)return open==0;
        if(dp[idx][open]!=-1)return dp[idx][open];

        bool isValid=0;

        if(s[idx]=='*'){
            isValid |= f(idx+1,open+1,s,n);
            isValid |= f(idx+1,open,s,n);
            if(open>0) isValid |= f(idx+1,open-1,s,n);
        }
        else if(s[idx]=='(') isValid |= f(idx+1,open+1,s,n);
        else if(open>0) isValid |= f(idx+1,open-1,s,n);

        return dp[idx][open]=isValid;
    }

    bool checkValidString(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,s,n);
    }
};