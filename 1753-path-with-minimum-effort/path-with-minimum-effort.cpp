class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    int minimumEffortPath(vector<vector<int>>& heights){
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<
                pair<int,pair<int,int>>,
                vector<pair<int,pair<int,int>>>,
                greater<pair<int,pair<int,int>>>
        >pq;
        pq.push({0,{0,0}});

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;

        while(!pq.empty()){

            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;

            pq.pop();

            for(auto it:dir){
                int nr=row+it[0];
                int nc=col+it[1];

                if(nr>=0 && nc>=0 && nr<=n-1 && nc<=m-1){
                    int newEffort=max(abs(heights[nr][nc]-heights[row][col]),diff);
                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]=newEffort;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};