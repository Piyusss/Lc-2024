class Solution {
    private:
    void dfs(vector<int>adjLs[],vector<int>&vis,int node){
        vis[node]=1;
        for(auto it:adjLs[node]){
            if(!vis[it]){
                dfs(adjLs,vis,it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& adjMat) {
        int n=adjMat.size();
        vector<int>adjLs[n+1];
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(adjMat[i][j]==1 && i!=j){
                    adjLs[i+1].push_back(j+1);
                    adjLs[j+1].push_back(i+1);
                }
            }
        }
        vector<int>vis(n+1);
        int cnt=0;
        for(int i=1 ; i<=n ; i++){
            if(!vis[i]){
                cnt++;
                dfs(adjLs,vis,i);
            }
        }
        return cnt;   
    }
};