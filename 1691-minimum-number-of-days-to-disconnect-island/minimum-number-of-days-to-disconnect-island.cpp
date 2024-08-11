class Solution {
public:

vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;

void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid){
    vis[i][j]=1;

    for(auto &it:dir){
        int ni=i+it[0];
        int nj=j+it[1];

        if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]==1){
            dfs(ni,nj,vis,grid);
        }
    }
}
    int minDays(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int mark=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,vis,grid);
                    mark=1;
                    cnt++;
                }
            }
        }

        if(cnt>1 || !mark)return 0;
        
        vis.clear();
        vector<vector<int>>vis2(n,vector<int>(m,0));
        vector<vector<int>>vis3(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int cnt2=0;
                    vis2=vis3;
                    for(int k=0;k<n;k++){
                        for(int l=0;l<m;l++){
                            if(!vis2[k][l] && grid[k][l]==1){
                                dfs(k,l,vis2,grid);
                                cnt2++;
                            }
                        }
                    }
                    if(cnt2>1 || !cnt2)return 1;
                    grid[i][j]=1;
                }
            }
        }

        return 2;
    }
};