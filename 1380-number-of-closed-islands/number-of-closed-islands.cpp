class Solution {
public:

    int n,m;
    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

    void dfs(int i,int j,vector<vector<int>>&grid){
        grid[i][j]=1;

        for(auto &it:dir){
            int new_i=i+it[0];
            int new_j=j+it[1];

            if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && grid[new_i][new_j]==0){
                dfs(new_i,new_j,grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        //top
        for(int j=0;j<m;j++){
            if(grid[0][j]==0){
                dfs(0,j,grid);
            }
        }

        //right
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==0){
                dfs(i,m-1,grid);
            }
        }

        //bottom
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==0){
                dfs(n-1,j,grid);
            }
        }

        //left
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                dfs(i,0,grid);
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        
        return cnt;
    }
};