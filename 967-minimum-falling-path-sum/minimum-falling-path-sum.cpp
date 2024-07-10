class Solution {
public:

int dp[101][101];

int f(vector<vector<int>>&m, int i,int j,int n){
    for(int k=0;k<n;k++)dp[0][k]=m[0][k];

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int up=m[i][j] + (i>=1 ? dp[i-1][j] : 1e9 );
            int dl=m[i][j] + (i>=1 && j>=1 ? dp[i-1][j-1] : 1e9);
            int dr=m[i][j] + (i>=1 && j<=n-2 ? dp[i-1][j+1] : 1e9);
            dp[i][j]=min(up,min(dr,dl));
        }
    }

    int mini=INT_MAX;
    for(int i=0;i<n;i++)mini=min(mini,dp[n-1][i]);
    return mini;
}
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int mini=1e9;
        for(int j=0;j<n;j++){
            memset(dp,-1,sizeof(dp));
            mini=min(mini,f(mat,1,n-1,n));
        }
        return mini;
    }
};