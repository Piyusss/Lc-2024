class Solution {
public:

int n,m;
vector<vector<int>>dir={{0,1},{-1,1},{1,1}};
int maxi=0;

void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int cnt){
    vis[i][j]=1;
    maxi=max(maxi,cnt);

    for(auto &it:dir){
        int ni=i+it[0];
        int nj=j+it[1];

        if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && grid[ni][nj]>grid[i][j]){
            dfs(ni,nj,grid,vis,cnt+1);
        }
    }
}
    int maxMoves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0]){
                dfs(i,0,grid,vis,0);
            }
        }

        return maxi;
    }
};