class Solution {
public:
    const int M=1E9+7;

    vector<int>lv,p;
    vector<vector<int>>up,g;

    void dfs(int u,int d){
        lv[u]=d;
        for(auto &v:g[u]) dfs(v,d+1);
    }

    void build(int n){
        for(int i=1;i<n;i++) up[0][i]=p[i];
        for(int i=1;i<17;i++) for(int j=1;j<n;j++) up[i][j]=up[i-1][up[i-1][j]];
    }

    int lca(int a,int b){
        if(lv[a]>lv[b]) swap(a,b);

        int k=lv[b]-lv[a];
        for(int i=16;i>=0;i--) if(k&(1<<i)) b=up[i][b];

        if(a==b) return a;

        for(int i=16;i>=0;i--){
            if(up[i][a]!=up[i][b]){
                a=up[i][a];
                b=up[i][b];
            }
        }

        return up[0][a];
    }

    int pw(long long a,long long b){
        long long r=1;
        a%=M;

        while(b){
            if(b&1) r=r*a%M;
            a=a*a%M;
            b>>=1;
        }

        return r;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& e,vector<vector<int>>& q) {
        int n=e.size()+2;

        lv.assign(n,0);
        p.assign(n,0);
        up.assign(17,vector<int>(n));
        g.assign(n+1,{});

        bool f=0;
        for(auto &x:e){
            if(x[1]==1){
                f=1;
                break;
            }
        }

        for(auto &x:e){
            int a=x[0],b=x[1];

            if(f){
                g[b].push_back(a);
                p[a]=b;
            }
            else{
                g[a].push_back(b);
                p[b]=a;
            }
        }

        dfs(1,0);
        build(n);

        vector<int>r;
        for(auto &x:q){
            int a=x[0],b=x[1];

            if(a==b){
                r.push_back(0);
                continue;
            }

            int m=lca(a,b),d=lv[a]+lv[b]-2*lv[m];
            r.push_back(pw(2,d-1));
        }

        return r;
    }
};