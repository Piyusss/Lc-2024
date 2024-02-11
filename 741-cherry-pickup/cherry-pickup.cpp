class Solution {
public:
    int dp[50][50][50];
    int f(int n,vector<vector<int>>&grid,
    int r1,int c1,int c2){
        int r2=r1+c1-c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)return -1e8;
        if((r1==n-1 && c1==n-1) || (r2==n-1 && c2==n-1))return grid[r1][c1];

        if(dp[r1][c1][c2]!=-1)return dp[r1][c1][c2];
        
        int ans=grid[r1][c1];
        if(c1!=c2)ans+=grid[r2][c2];

        int maxi=-1e8;
                maxi=max(maxi,f(n,grid,r1,c1+1,c2+1));
                maxi=max(maxi,f(n,grid,r1,c1+1,c2));
                maxi=max(maxi,f(n,grid,r1+1,c1,c2));
                maxi=max(maxi,f(n,grid,r1+1,c1,c2+1));

        ans+=maxi;
        return dp[r1][c1][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid){
        int n=grid.size();
        memset(dp, -1, sizeof(dp));
        return max(0,f(n,grid,0,0,0));
    }
};