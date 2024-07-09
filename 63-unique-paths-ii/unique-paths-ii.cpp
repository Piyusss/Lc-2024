class Solution {
public:

int dp[101][101];

    int uniquePathsWithObstacles(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0])return 0;

        memset(dp,0,sizeof(dp));
        dp[0][0]=1;

        for(int i=0;i<=n-1;i++){
            for(int j=0;j<=m-1;j++){
                if(i==0 && j==0)continue;
                if(grid[i][j]==1){dp[i][j]=0;continue;}
                
                dp[i][j]= (i>=1 ? dp[i-1][j] : 0) + (j>=1 ? dp[i][j-1] : 0);
            }
        }

        return dp[n-1][m-1];

    }
};