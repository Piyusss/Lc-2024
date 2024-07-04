class Solution {
public:
    int minimumTotal(vector<vector<int>>&grid){
        int n=grid.size();
        vector<vector<int>>dp=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<dp[i].size();j++){
                dp[i][j]=0;
            }
        }
        //base-case-in-tabulation
        for(int i=0;i<grid[n-1].size();i++){
            dp[n-1][i]=grid[n-1][i];
        }
        //now
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<grid[i].size();j++){
                int down=grid[i][j]+dp[i+1][j];
                int diag=grid[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];
    }
};