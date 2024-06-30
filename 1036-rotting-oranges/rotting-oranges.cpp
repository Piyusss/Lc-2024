class Solution {
public:
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<pair<int,int>,int>>q;
        int ans=0;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        
        while(!q.empty()){
            int qr=q.front().first.first;
            int qc=q.front().first.second;
            int t=q.front().second;
            q.pop();

            ans=max(ans,t);

            for(auto it:dir){
                int nr=qr+it[0];
                int nc=qc+it[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},t+1});
                }
            }       
        }
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==1 && vis[i][j]!=1)return -1;
            }
        }
        return ans;
    }
};