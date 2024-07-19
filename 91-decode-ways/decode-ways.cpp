class Solution {
public:

int dp[101];

    int numDecodings(string s){
        int n=s.size();
        memset(dp,0,sizeof(dp));
        
        dp[n]=1;

        for(int idx=n-1;idx>=0;idx--){
            if(s[idx]=='0')continue;

            int res=dp[idx+1];
            if( ( idx+1<=n-1 && s[idx]=='1') || ( idx+1<=n-1 && s[idx]=='2' && s[idx+1]<='6' ))res+=dp[idx+2];
            dp[idx]= res;
        }
    
        return dp[0];
    }
};