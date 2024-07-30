class Solution {
public:

int maxi=-1;

void dfs(int node,vector<int>&edges,vector<int>&vis,vector<int>&pathVis,vector<int>& cnt,int flag){
    vis[node]=1;
    pathVis[node]=1;
    cnt[node]=flag;

    int it=edges[node];

    if(it!=-1 && !vis[it]){
        dfs(it,edges,vis,pathVis,cnt,flag+1);
    }
    else if(it!=-1 && pathVis[it]){
        maxi=max(maxi,cnt[node]-cnt[it]+1);
    }

    pathVis[node]=0;
}

    int longestCycle(vector<int>& edges){
        int n=edges.size();

        vector<int>vis(n);
        vector<int>pathVis(n);
        vector<int>cnt(n);
        int flag=1;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,edges,vis,pathVis,cnt,flag);
            }
        }

        return maxi==-1 ? -1 : maxi;
    }
};