using ll=long long;

class Solution {
    void sub(int u, vector<vector<int>>&g, int p, vector<ll>&s){
        for(int &v:g[u])if(v!=p){
            sub(v,g,u,s);
            s[u]+=s[v];
        }
    }

    int c=0;
    void dfs(int u, vector<vector<int>>&g, int p, vector<ll>&s,int k){
        for(int &v:g[u])if(v!=p){
            ll a=s[u]-s[v],b=s[v];

            if(a%k==0 && b%k==0){
                c++;
                s[u]-=s[v];
            }
            else s[v]=s[u];

            dfs(v,g,u,s,k);
        }
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>&e, vector<int>&val, int k) {
        vector<vector<int>>g(n);

        for(auto &x:e) g[x[0]].push_back(x[1]),g[x[1]].push_back(x[0]);

        vector<ll>s(val.begin(),val.end());
        sub(0,g,-1,s);

        dfs(0,g,-1,s,k);
        return c+1;
    }
};