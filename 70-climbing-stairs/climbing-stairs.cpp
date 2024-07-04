class Solution {
public:

int dp[45+1];

int f(int n){
    if(n<=1)return 1;
    if(dp[n]!=-1)return dp[n];
    
    return dp[n]=f(n-1)+f(n-2);
}
    int climbStairs(int n){
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};