class Solution {
public:

    int size_of_island=0;
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,int n,int m){
        vis[i][j]=1;
        size_of_island++;

        for(auto &c:dir){
            int ni=i+c.first;
            int nj=j+c.second;

            if(ni>=0 && ni<=n-1 && nj>=0 && nj<=m-1 && !vis[ni][nj] && grid[ni][nj]==1) dfs(ni,nj,vis,grid,n,m);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    size_of_island=0;
                    dfs(i,j,vis,grid,n,m);
                    maxi=max(maxi,size_of_island);
                }
            }
        }

        return maxi;
    }
};