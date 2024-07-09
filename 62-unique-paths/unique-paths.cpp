class Solution {
public:

int dp[102][102];

    int uniquePaths(int n, int m){
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;

        for(int i=0;i<=n-1;i++){
            for(int j=0;j<=m-1;j++){
                if(i==0 && j==0)continue;
                dp[i][j]= (i>=1 ? dp[i-1][j] : 0) + (j>=1 ? dp[i][j-1] : 0);
            }
        }

        return dp[n-1][m-1];
    }
};