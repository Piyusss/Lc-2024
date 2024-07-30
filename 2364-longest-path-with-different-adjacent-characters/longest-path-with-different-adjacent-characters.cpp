class Solution {
public:

int maxi=0;

int dfs(int node,int par,vector<int> adjList[],string &s){
    int longest=0;
    int secondLongest=0;

    for(auto &it:adjList[node]){
        if(it==par)continue;

        int longestNodeLength=dfs(it,node,adjList,s);

        if(s[it]==s[node])continue;

        if(longestNodeLength>secondLongest)secondLongest=longestNodeLength;
        if(secondLongest>longest)swap(longest,secondLongest);

    }

    int both=longest+secondLongest+1;
    int alone=1;
    int elongate=max(longest,secondLongest)+1;

    maxi=max({maxi,both,alone,elongate});
    return max(alone,elongate);
}
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();

        vector<int>adjList[n+1];

        for(int i=0;i<n;i++){
            int u=parent[i];
            int v=i;
            if(u!=-1 && v!=-1){
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        dfs(0,-1,adjList,s);
        return maxi;

    }
};