class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;

        for(int i=0;i<=m-1;i++){
            for(int j=0;j<=n-1;j++){
                if(i+j==0)continue;
                int up=0;
                int left=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1]; 
    }
};