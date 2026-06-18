class Solution {
public:

    int dp[46];

    int f(int n){
        if(n==0) return 1;

        if(dp[n] != -1) return dp[n];

        int cnt=0;
        cnt += f(n-1);
        if(n-2>=0) cnt += f(n-2);

        return dp[n]=cnt;
    }

    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};