class Solution {
public:

int dp[30+1][1000+1];
int M=1E9+7;

int f(int nthDice,int k,int target){
    if(target<0)return 0;
    if(target==0 && nthDice==0)return 1;
    if(target!=0 && nthDice==0)return 0;

    if(dp[nthDice][target]!=-1)return dp[nthDice][target];

    int cnt=0;
    for(int face=1;face<=k;face++){
        cnt= (cnt+f(nthDice-1,k,target-face))%M;
    }
    return dp[nthDice][target]= cnt%M;
}
    int numRollsToTarget(int n, int k, int target){
        memset(dp,-1,sizeof(dp));
        return f(n,k,target)%M;
    }
};