class Solution {
public:

int n,m;
int mini=INT_MAX;
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

    int minTimeToReach(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});

        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int d=it.first;
            int x=it.second.first;
            int y=it.second.second;

            for(auto &it:dir){
                int nx=x+it[0];
                int ny=y+it[1];
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int wait= (dis[x][y] < grid[nx][ny]) ? (grid[nx][ny]-dis[x][y]) : 0 ; 
                    if(dis[x][y]+1+wait<dis[nx][ny]){
                        dis[nx][ny] = dis[x][y]+1+wait;
                        pq.push({dis[nx][ny],{nx,ny}});
                    }
                }
            }
        }

        return dis[n-1][m-1];

    }
};