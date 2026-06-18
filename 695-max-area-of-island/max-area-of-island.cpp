class Solution {
public:

    int size_of_island=0;
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(int i,int j,vector<vector<int>>&grid,int n,int m){
        grid[i][j]=-1;
        size_of_island++;

        for(auto &c:dir){
            int ni=i+c.first;
            int nj=j+c.second;

            if(ni>=0 && ni<=n-1 && nj>=0 && nj<=m-1 && grid[ni][nj]==1) dfs(ni,nj,grid,n,m);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    size_of_island=0;
                    dfs(i,j,grid,n,m);
                    maxi=max(maxi,size_of_island);
                }
            }
        }

        return maxi;
    }
};