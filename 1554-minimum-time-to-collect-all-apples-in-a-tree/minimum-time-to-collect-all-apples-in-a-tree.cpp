class Solution {
public:
int dfs(int node,vector<int>adj[],vector<bool>hasApple,int par){
    int time=0;

    for(auto it:adj[node]){
        if(it==par)continue;
        int tim_from_child=dfs(it,adj,hasApple,node);
        
        if(tim_from_child>0 || hasApple[it]){
            time+=2+tim_from_child;
        }
    }
    return time;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        //now
        return dfs(0,adj,hasApple,-1);
    }
};