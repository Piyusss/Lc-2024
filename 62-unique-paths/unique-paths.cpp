class Solution {
public:

int dp[101][101];

int f(int i,int j){
    if(i==0 && j==0)return 1;
    if(i<0 || j<0)return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=f(i-1,j)+f(i,j-1);
}
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(m-1,n-1);
    }
};