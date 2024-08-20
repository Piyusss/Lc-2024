class Solution {
public:

int dp[1001][1001];

int f(int num,int copy,int n){
    if(num==n)return 0;
    if(num>n)return 1e3;

    if(dp[num][copy]!=-1)return dp[num][copy];

    int copied=2+f(2*num,num,n);
    int notCopied=1+f(num+copy,copy,n);

    return dp[num][copy]=min(copied,notCopied);
}
    int minSteps(int n){
        if(n==1)return 0;
        memset(dp,-1,sizeof(dp));
        return 2+f(2,1,n);
    }
};