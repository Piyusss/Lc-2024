class Solution {
public:

int sum=0;
int n,m;
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){

    vis[i][j]=1;
    sum+=grid[i][j];

    for(auto it:dir){
        int ni=i+it[0];
        int nj=j+it[1];

        if(ni>=0 && nj>=0 && ni<n && nj<m && vis[ni][nj]==0 && grid[ni][nj]>0){
            dfs(ni,nj,grid,vis);
        }
    }
}
    int findMaxFish(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]>0){
                    sum=0;
                    dfs(i,j,grid,vis);
                    maxi=max(maxi,sum);
                }
            }
        }

        return maxi;
    }
};