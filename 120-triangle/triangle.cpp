class Solution {
public:

    int minimumTotal(vector<vector<int>>&grid){
        int n=grid.size();

        vector<vector<int>>dp=grid;
        for(int i=0;i<n;i++) for(int j=0;j<dp[i].size();j++) dp[i][j]=0;
        
        for(int i=0;i<grid[n-1].size();i++) dp[n-1][i]=grid[n-1][i];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<grid[i].size();j++){
                dp[i][j]=min(grid[i][j]+dp[i+1][j],grid[i][j]+dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};