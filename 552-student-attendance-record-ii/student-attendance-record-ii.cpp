class Solution {
public:

int dp[100001][5][5];
int MOD=1e9+7;

int f(int absCnt,int latCnt,int idx){
    if(absCnt==2  ||  latCnt==3)return 0;
    if(idx==0)return 1;

    if(dp[idx][absCnt][latCnt]!=-1)return dp[idx][absCnt][latCnt];

    int ans=0;
    ans+=f(absCnt,0,idx-1);ans=ans%MOD;
    ans+=f(absCnt+1,0,idx-1);ans=ans%MOD;
    ans+=f(absCnt,latCnt+1,idx-1);ans=ans%MOD;

    return dp[idx][absCnt][latCnt]=ans%MOD;
}
    int checkRecord(int n){
        memset(dp,-1,sizeof(dp));
        return f(0,0,n);
    }
};