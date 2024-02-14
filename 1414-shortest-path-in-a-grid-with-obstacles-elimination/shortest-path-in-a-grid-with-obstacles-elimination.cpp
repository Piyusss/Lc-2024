class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        queue<vector<int>>q;
        int i=0,j=0;
        q.push({0,0,k});
        vector<vector<vector<int>>>vis(n+1,vector<vector<int>>(m+1,vector<int>(k+1,0)));

        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto cur=q.front();
                q.pop();

                int cur_i=cur[0];
                int cur_j=cur[1];
                int obs=cur[2];

                if(cur_i==n-1 && cur_j==m-1)return steps;

                for(auto it:dir){
                    int new_i=cur_i+it[0];
                    int new_j=cur_j+it[1];
                    if(new_i<0 || new_i>=n || new_j<0 || new_j>=m)continue;

                    if(grid[new_i][new_j]==0 && !vis[new_i][new_j][obs]){
                        q.push({new_i,new_j,obs});
                        vis[new_i][new_j][obs]=1;
                    }
                    else if(grid[new_i][new_j]==1 && obs>0 && !vis[new_i][new_j][obs]){
                        q.push({new_i,new_j,obs-1});
                        vis[new_i][new_j][obs]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};