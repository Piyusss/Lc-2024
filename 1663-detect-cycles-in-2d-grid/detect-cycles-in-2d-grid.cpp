class Solution {
public:

vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;

bool dfs(int i,int j, vector<vector<int>>& vis,vector<vector<char>>& grid,int par_i,int par_j){
    vis[i][j]=1;

    for(auto &it:dir){
        int ni=i+it[0];
        int nj=j+it[1];
        if(ni>=0 && ni<n && nj>=0 && nj<m && grid[i][j]==grid[ni][nj]){
            if(ni==par_i && nj==par_j)continue;
            if(!vis[ni][nj]){
                if(dfs(ni,nj,vis,grid,i,j))return 1;
            }
            else if(vis[ni][nj])return 1;
        }
    }
    return 0;
}
    bool containsCycle(vector<vector<char>>& grid){
        n=grid.size();
        m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j])continue;
                if(dfs(i,j,vis,grid,-1,-1))return 1;
            }
        }
        return 0;
    }
};