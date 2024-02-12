class Solution {
public:
    int N,M,K;
    int MOD=1e9+7;
    int dp[51][51][101];
    int f(int idx,int search_cost,int maxSoFar){
        if(idx==N){
            if(search_cost==K)return 1;
            return 0;
        }
        if(dp[idx][search_cost][maxSoFar]!=-1)return (dp[idx][search_cost][maxSoFar]);
        int ans=0;
        for(int i=1;i<=M;i++){
            if(i>maxSoFar)ans=(ans+f(idx+1,search_cost+1,i))%MOD;
            else ans=(ans+f(idx+1,search_cost,maxSoFar))%MOD;
        }
        return dp[idx][search_cost][maxSoFar]=ans%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));
        return f(0,0,0)%MOD;
    }
};