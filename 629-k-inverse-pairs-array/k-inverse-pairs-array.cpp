class Solution {
public:
    int mod=1e9+7;
    long long f(int n, int k,vector<vector<int>>&dp){
        if (k==0) return 1;
        if (k<0 || n<=0) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        return dp[n][k]=((f(n-1, k,dp)+f(n, k-1,dp))%mod-f(n-1, k-n,dp)+mod)%mod;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return f(n, k,dp);
    }
};