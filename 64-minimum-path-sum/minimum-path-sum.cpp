class Solution {
public:

int dp[201][201];

    int minPathSum(vector<vector<int>>& grid){
        int n=grid.size();int m=grid[0].size();
        memset(dp,0,sizeof(dp));
        dp[0][0]=grid[0][0];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)continue;
                dp[i][j]=min((i>=1 ? grid[i][j]+dp[i-1][j] : grid[i][j]+1e9),(j>=1 ? grid[i][j]+dp[i][j-1] : grid[i][j]+1e9));
            }
        }

        return dp[n-1][m-1];
    }
};