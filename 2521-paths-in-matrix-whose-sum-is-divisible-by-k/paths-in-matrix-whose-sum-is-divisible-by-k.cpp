using ll=long long;
const int mod=1E9+7;

class Solution {
    int n,m,k;
    vector<vector<int>>g;
    vector<vector<vector<int>>>dp;

    int dfs(int i,int j,int r){
        r=(r+g[i][j])%k;

        if(i==n-1 && j==m-1) return r==0;
        if(dp[i][j][r]!=-1) return dp[i][j][r];

        ll ans=0;
        if(i+1<n) ans+=dfs(i+1,j,r);
        if(j+1<m) ans+=dfs(i,j+1,r);

        return dp[i][j][r]=ans%mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& a, int K) {
        g=a;
        k=K;

        n=g.size();
        m=g[0].size();

        dp.assign(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return dfs(0,0,0);
    }
};