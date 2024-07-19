class Solution {
public:

int dp[30+1][1000+1];
int M=1E9+7;

    int numRollsToTarget(int n, int k, int target){
        memset(dp,0,sizeof(dp));
        
        dp[0][0]=1;

        for(int nthDice=1;nthDice<=n;nthDice++){
            for(int t=1;t<=target;t++){
                int cnt=0;
                for(int face=1;face<=k;face++){
                    if(t-face>=0)cnt= (cnt+dp[nthDice-1][t-face])%M;
                }
                dp[nthDice][t]= cnt%M;
            }
        }
        return dp[n][target];
    }
};