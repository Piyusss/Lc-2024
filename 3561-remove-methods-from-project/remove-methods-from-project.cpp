class Solution {
public:

    unordered_set<int>removed;

    void dfs(int node,vector<int>adjList[],vector<int>&vis){
        vis[node]=1;
        removed.insert(node);

        for(auto &it:adjList[node]){
            if(!vis[it])dfs(it,adjList,vis);
        }
    }

    bool check(int node,vector<int>adjList[]){
        for(auto &it:adjList[node]){
            if(removed.find(it)!=removed.end()){
                return 0;
            }
        }
        return 1;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& nums) {
        vector<int>adjList[n];

        for(auto &it:nums) adjList[it[0]].push_back(it[1]);

        vector<int>vis(n,0);
        dfs(k,adjList,vis);

        vector<int>res;
        for(int i=0;i<n;i++)res.push_back(i);
        
        for(int i=0;i<n;i++){
            if(removed.find(i)==removed.end()){
                if(!check(i,adjList)) return res;
            }
        }
        res.clear();

        for(int i=0;i<n;i++){
            if(removed.find(i)==removed.end())res.push_back(i);
        }

        return res;
    }
};