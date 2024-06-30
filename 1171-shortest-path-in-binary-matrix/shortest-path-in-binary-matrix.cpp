class Solution {
public:
int n,m;
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        if(grid[0][0]==1)return -1;

        priority_queue<
            pair<pair<int,int>,int>,
            vector<pair<pair<int,int>,int>>,
            greater<pair<pair<int,int>,int>>
        >pq;

        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=1;

        pq.push({{0,0},1});

        while(!pq.empty()){
            int xc=pq.top().first.first;
            int yc=pq.top().first.second;
            int d=pq.top().second;

            pq.pop();

            for(auto it:dir){
                int nxc=xc+it[0];
                int nyc=yc+it[1];

                if(nxc>=0 && nxc<n && nyc>=0 && nyc<m && grid[nxc][nyc]==0){
                    if(d+1<dis[nxc][nyc]){
                        dis[nxc][nyc]=d+1;
                        pq.push({{nxc,nyc},dis[nxc][nyc]});
                    }
                }
            }
        }

        if(dis[n-1][m-1]==1e9)return -1;
        else return dis[n-1][m-1];
    }
};