class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;

        vector<int>adj[100001];
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                adj[routes[i][j]].push_back(i);
            }
        }
        //now
        queue<int>q;
        vector<int>vis(501,0);
        for(auto it:adj[source]){
            q.push(it);
            vis[it]=1;
        }
        //now
        int cnt=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int cur=q.front();
                q.pop();

            for(auto stop:routes[cur]){
                if(stop==target)return cnt;
                
                for(auto nextRoute:adj[stop]){
                    if(!vis[nextRoute]){
                        vis[nextRoute]=1;
                        q.push(nextRoute);
                    }
                }
            }
          }
          cnt++;
        }
        return -1;
    }
};