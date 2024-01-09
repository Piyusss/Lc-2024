class Solution {
public:
void dfs(int node,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>adj[n];
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        //now
        vector<int>vis(n,0);
        dfs(0,vis,adj);
        //now
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return 0;
            }
        }
        return 1;
    }
};