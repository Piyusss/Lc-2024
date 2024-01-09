class Solution {
public:
void dfs(int ind,vector<vector<int>>&stones,vector<int>&vis){
    vis[ind]=1;
    for(int i=0;i<stones.size();i++){
        if(vis[i])continue;
        int cr=stones[ind][0];
        int cc=stones[ind][1];

        if(!vis[i] && 
        (stones[i][0]==cr || stones[i][1]==cc)){
            dfs(i,stones,vis);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>vis(n,0);

        int nocc=0;
        for(int i=0;i<n;i++){
            if(vis[i]){
                continue; 
            }
            dfs(i,stones,vis);
            nocc++;
        }
        return n-nocc;
    }
};