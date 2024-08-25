class Solution {
public:

int res=0;

void dfs(vector<int>adjList[],int node,vector<int>& vis,int time,vector<int>& informTime){
    vis[node]=1;
    res=max(res,time);

    for(auto &it:adjList[node]){
        if(!vis[it]){
            dfs(adjList,it,vis,time+informTime[node],informTime);
        }
    }
}

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adjList[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1) adjList[i].push_back(manager[i]);
            if(manager[i]!=-1) adjList[manager[i]].push_back(i);
        }

        vector<int>vis(n,0);
        dfs(adjList,headID,vis,0,informTime);

        return res;
    }
};