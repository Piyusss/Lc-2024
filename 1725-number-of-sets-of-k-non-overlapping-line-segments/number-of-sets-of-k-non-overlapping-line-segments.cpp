using ll=long long;

class Solution {
public:

    int mod=1e9+7;

    ll f(int n,int k,int i,int c,bool x,vector<vector<vector<ll>>>&dp){
        if(!c) return 1;
        if(i==n) return 0;

        if(dp[i][c][x]!=-1) return dp[i][c][x];

        ll a=0;
        if(!x){
            a=(a+f(n,k,i+1,c,0,dp))%mod;
            a=(a+f(n,k,i+1,c,1,dp))%mod;
        }
        else{
            a=(a+f(n,k,i+1,c,1,dp))%mod;
            a=(a+f(n,k,i,c-1,0,dp))%mod;
        }

        return dp[i][c][x]=a;
    }

    int numberOfSets(int n,int k) {
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(k+1,vector<ll>(2,-1)));
        return f(n,k,0,k,0,dp);
    }
};