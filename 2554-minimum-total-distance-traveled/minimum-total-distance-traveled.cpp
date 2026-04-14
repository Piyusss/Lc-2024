using ll=long long;

class Solution {
public:

    map<string,ll>mpp;
    ll dp[200][20000];

    ll f(int i,int j,vector<int>&r,vector<int>&v){
        if(i==r.size()) return 0LL;
        if(j==v.size()) return 1e16;
        
        if(dp[i][j]!=-1) return dp[i][j];

        ll ans=1e16;
        ans=min(ans,f(i,j+1,r,v));
        ans=min(ans,abs(r[i]-v[j])+f(i+1,j+1,r,v));

        return dp[i][j] = ans; 
    }

    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& v) {
        sort(r.begin(),r.end());
        sort(v.begin(),v.end());

        vector<int>v2;
        for(auto &it:v) for(int i=0;i<it[1];i++) v2.push_back(it[0]);

        memset(dp,-1,sizeof(dp));
        return f(0,0,r,v2);
    }
};