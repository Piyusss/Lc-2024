class Solution {
public:

int dp[101][101];
int n,m;

int f(int i,int j){
    if(i==n-1 && j==m-1) return 1;
    if(i==n || j==m) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int right=f(i,j+1);
    int down=f(i+1,j);
    
    return dp[i][j]=down+right;
}
    int uniquePaths(int N, int M) {
        n=N;
        m=M;

        memset(dp,-1,sizeof(dp));
        return f(0,0);
    }
};