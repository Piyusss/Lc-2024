class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adjList[n];

        for(auto it:roads){
            int u=it[0];
            int v=it[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int u=i;
                int v=j;
                int ans=0;

                if(find(adjList[u].begin(),adjList[u].end(),v)!=adjList[u].end())ans--;

                ans+=adjList[u].size();
                ans+=adjList[v].size();

                maxi=max(maxi,ans);
            }
        }

        return maxi;
    }
};