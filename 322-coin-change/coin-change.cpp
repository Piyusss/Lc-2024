class Solution {
public:
    int coinChange(vector<int>& num, int x) {
    int n=num.size();
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));

    for(int T=0;T<=x;T++){
        if(T%num[0]==0)dp[0][T]=T/num[0];
        else dp[0][T]=1e9;
    }

    for(int ind=1;ind<=n-1;ind++){
        for(int T=0;T<=x;T++){
            int notTake=0+dp[ind-1][T];
            int take=1e9;
            if(num[ind]<=T)take=1+dp[ind][T-num[ind]];
            dp[ind][T]=min(take,notTake);
        }
    }
    
    if(dp[n-1][x]>=1e9)return -1;
    return dp[n-1][x];
    }
};