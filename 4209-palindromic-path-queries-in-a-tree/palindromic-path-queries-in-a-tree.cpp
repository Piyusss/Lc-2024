class Solution {
public:

    static const int LOG=21;

    struct Fenwick {
        int n;
        vector<int>b;

        Fenwick(int n):n(n),b(n+1){}

        void add(int i,int x){
            for(i++;i<=n;i+=i&-i) b[i]^=x;
        }

        int sum(int i){
            int x=0;
            for(i++;i>0;i-=i&-i) x^=b[i];
            return x;
        }
    };

    int mask(char c){
        return 1<<(c-'a');
    }

    void dfs(int u,int p,vector<vector<int>>&g,vector<vector<int>>&par,vector<int>&d,vector<int>&tin,vector<int>&tout,int&tm){
        tin[u]=tm++;
        par[0][u]=p;

        for(int v:g[u]){
            if(v==p) continue;
            d[v]=d[u]+1;
            dfs(v,u,g,par,d,tin,tout,tm);
        }

        tout[u]=tm-1;
    }

    int lca(int u,int v,vector<vector<int>>&par,vector<int>&d){
        if(d[u]<d[v]) swap(u,v);

        int x=d[u]-d[v];
        for(int i=0;i<LOG;i++) if(x>>i&1) u=par[i][u];
        if(u==v) return u;

        for(int i=LOG-1;i>=0;i--){
            if(par[i][u]!=par[i][v]){
                u=par[i][u];
                v=par[i][v];
            }
        }

        return par[0][u];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>>g(n);

        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<vector<int>>par(LOG,vector<int>(n,-1));
        vector<int>d(n),tin(n),tout(n);
        int tm=0;

        dfs(0,-1,g,par,d,tin,tout,tm);

        for(int i=1;i<LOG;i++){
            for(int j=0;j<n;j++){
                int p=par[i-1][j];
                if(p!=-1) par[i][j]=par[i-1][p];
            }
        }

        Fenwick f(n);

        for(int i=0;i<n;i++){
            int x=mask(s[i]);
            f.add(tin[i],x);
            f.add(tout[i]+1,x);
        }

        vector<bool>ans;

        for(auto &q:queries){
            stringstream ss(q);
            string t;
            ss>>t;

            if(t=="update"){
                int u;
                char c;
                ss>>u>>c;

                int x=mask(s[u])^mask(c);
                s[u]=c;

                f.add(tin[u],x);
                f.add(tout[u]+1,x);
            }
            else{
                int u,v;
                ss>>u>>v;

                int w=lca(u,v,par,d);
                int x=f.sum(tin[u])^f.sum(tin[v])^mask(s[w]);

                ans.push_back(!x||!(x&(x-1)));
            }
        }

        return ans;
    }
};