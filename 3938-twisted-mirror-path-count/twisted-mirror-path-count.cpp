class Solution {
public:

    const int MOD=1E9+7;
    int dp[500][500][2][2];

    int f(int i,int j,int n,int m,vector<vector<int>>&grid,bool d,bool r){
        if(i==n-1 && j==m-1) return 1;
        if(i<0 || j<0 || i>n-1 || j>m-1) return 0;

        if(dp[i][j][d][r] != -1) return dp[i][j][d][r];

        int down=0,right=0;
        
        if(grid[i][j]==0){
            down+=f(i+1,j,n,m,grid,1,0); down %= MOD;
            right+=f(i,j+1,n,m,grid,0,1); right %= MOD;
        }
        else{
            if(r) down+=f(i+1,j,n,m,grid,1,0); down %= MOD;
            if(d) right+=f(i,j+1,n,m,grid,0,1); right %= MOD;
        }

        return dp[i][j][d][r] = (down+right) % MOD;
    }
    
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        memset(dp,-1,sizeof(dp));
        return f(0,0,n,m,grid,0,0)%MOD;
    }
};