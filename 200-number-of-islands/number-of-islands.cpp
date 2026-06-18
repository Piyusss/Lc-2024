class Solution {
public:

    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid,int n,int m){
        vis[i][j]=1;

        for(auto &c:dir){
            int ni=i+c.first;
            int nj=j+c.second;

            if(ni>=0 && ni<=n-1 && nj>=0 && nj<=m-1 && !vis[ni][nj] && grid[ni][nj]=='1') dfs(ni,nj,vis,grid,n,m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,vis,grid,n,m);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};