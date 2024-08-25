class Solution {
public:

int n,m;
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

void dfs1(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis1){
    vis1[i][j]=1;

    for(auto &it:dir){
        int ni=i+it[0];
        int nj=j+it[1];

        if(ni>=0 && ni<n && nj>=0 && nj<m && !vis1[ni][nj] && grid[ni][nj]==1){
            dfs1(ni,nj,grid,vis1);
        }
    }
}
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        int start_i=-1;
        int start_j=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && start_i==-1 && start_j==-1){
                    start_i=i;
                    start_j=j;
                }
            }
        }

        cout<<start_i<<" "<<start_j;

        vector<vector<int>>vis1(n,vector<int>(m,0));
        dfs1(start_i,start_j,grid,vis1);

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis2(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j]==1){
                    q.push({{i,j},0});
                    vis2[i][j]=1;
                }
            }
        }

        int res=INT_MAX;

        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto p=q.front();
                int i=p.first.first;
                int j=p.first.second;
                int step=p.second;
                q.pop();

                if(vis1[i][j]==0 && grid[i][j]==1)res=min(res,step);

                for(auto &it:dir){
                    int ni=i+it[0];
                    int nj=j+it[1];

                    if(ni>=0 && nj>=0 && ni<n && nj<m && !vis2[ni][nj]){
                        vis2[ni][nj]=1;
                        q.push({{ni,nj},step+1});
                    }
                }

            }
        }

        return res-1;

    }
};