class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();

        if(n<=1)return 0;
        


        queue<pair<int,int>>q;
        set<pair<int,int>>vis;

        for(int i=0;i<n;i++){
            q.push({i,1<<i});
            vis.insert({i,1<<i});
        }

        int last=(1<<n)-1;
        int cnt=0;

        while(!q.empty()){
            int sz=q.size();
            cnt++;

            while(sz--){
                auto it=q.front();
                q.pop();

                int node=it.first;
                int cur_bitmask=it.second;


                for(auto it2:graph[node]){
                    int neg_bitmask=(1<<it2);
                    int new_bitmask=cur_bitmask | neg_bitmask;
                    if(new_bitmask==last)return cnt;

                    if(vis.count({it2,new_bitmask})==0){
                        vis.insert({it2,new_bitmask});
                        q.push({it2,new_bitmask});
                    }
                }
            }
        }
        return 0;
    }
};