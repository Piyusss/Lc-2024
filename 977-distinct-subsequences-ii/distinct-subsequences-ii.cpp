using ll=long long;

class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size(),mod=1E9+7;

        vector<ll>dp(n+1);
        vector<int>last(26,-1);

        dp[0]=1;

        for(int i=0;i<n;i++){
            dp[i+1]=2*dp[i]%mod;
            int c=s[i]-'a';
            
            if(last[c]!=-1) dp[i+1]=(dp[i+1]-dp[last[c]]+mod)%mod;
            last[c]=i;
        }

        return (dp[n]-1+mod)%mod;
    }
};