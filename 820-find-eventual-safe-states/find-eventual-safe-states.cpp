class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>adj[V+5];
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        //now
        vector<int>adjRev[V];
        vector<int>inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        //now
        queue<int>q;
        vector<int>safeNodes;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        //now
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            safeNodes.push_back(node);
            for(auto it:adjRev[node]){
                inDegree[it]--;
                if(inDegree[it]==0)q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};