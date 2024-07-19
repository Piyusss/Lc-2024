class Solution {
public:

int dp[100000][14];
vector<int>adjList[100000+1];

int dfs(vector<int>& coins, int k,int node,int par,int power){
    if(power>=14)return 0;

    if(dp[node][power]!=-1)return dp[node][power];

    int firstScenerio=(coins[node]>>power)-k;
    int secondScenerio=(coins[node]>>(power+1));

    for(auto &neg:adjList[node]){
        if(neg!=par){
            firstScenerio+=dfs(coins,k,neg,node,power);
            secondScenerio+=dfs(coins,k,neg,node,power+1);
        }
    }

    return dp[node][power]=max(firstScenerio,secondScenerio);
}
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n=coins.size();
        // unordered_map<int,vector<int>>adjList(n);
        memset(dp,-1,sizeof(dp));

        for(auto& it:edges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return dfs(coins,k,0,-1,0);
    }
};