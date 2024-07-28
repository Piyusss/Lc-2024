class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adjList[n+1];

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        pq.push({0,1});

        vector<int>dis1(n+1,INT_MAX);
        vector<int>dis2(n+1,INT_MAX);
        dis1[1]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int timeElapsed=it.first;
            int node=it.second;


            int flag=timeElapsed/change;
            if(flag%2==1){
                timeElapsed=(flag+1)*change;
            }


            for(auto &it2:adjList[node]){
                if( timeElapsed+time < dis1[it2] ){
                    dis2[it2]=dis1[it2];
                    dis1[it2]=timeElapsed+time;
                    pq.push({timeElapsed+time,it2});
                }
                else if( timeElapsed+time<dis2[it2] && timeElapsed+time!=dis1[it2]){
                    dis2[it2]=timeElapsed+time;
                    pq.push({timeElapsed+time,it2});
                }
            }
        }
        return dis2[n];
    }
};