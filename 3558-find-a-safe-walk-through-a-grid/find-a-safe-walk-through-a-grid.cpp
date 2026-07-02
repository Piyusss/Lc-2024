class Solution {
public:

    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=grid[0][0];

        priority_queue< pair<pair<int,int>,int> , vector<pair<pair<int,int>,int>> , greater<pair<pair<int,int>,int>> >pq;
        pq.push({{0,0},grid[0][0]});

        while(!pq.empty()){
            auto it=pq.top();
            int x=it.first.first;
            int y=it.first.second;
            int d=it.second;

            pq.pop();

            for(auto &it:dir){
                int nx=x+it[0];
                int ny=y+it[1];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(dis[x][y] + grid[nx][ny] < dis[nx][ny]){
                        dis[nx][ny]=dis[x][y] + grid[nx][ny];
                        pq.push({{nx,ny},dis[nx][ny]});
                    }
                }
            }
        }

        return health-dis[n-1][m-1]>=1;
    }
};