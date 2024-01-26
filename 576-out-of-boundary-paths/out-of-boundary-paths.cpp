class Solution {
public:
int M=1e9+7;
int f(int m, int n, int maxMove, int i, int j,
      vector<vector<vector<int>>>&dp){
    if(i==m || j==n || i<0 || j<0)return 1;
    if(maxMove==0)return 0;
    if(dp[i][j][maxMove]!=-1)return dp[i][j][maxMove]%M;

    return dp[i][j][maxMove]=
           ((f(m,n,maxMove-1,i,j+1,dp)+
           f(m,n,maxMove-1,i,j-1,dp))%M+

           (f(m,n,maxMove-1,i+1,j,dp)+
           f(m,n,maxMove-1,i-1,j,dp))%M)%M;
}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return f(m,n,maxMove,startRow,startColumn,dp)%M;
    }
};