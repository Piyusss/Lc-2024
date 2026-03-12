using ll=long long;

class DSU {
public:
    vector<int>p,r;

    DSU(int n){
        p.resize(n);
        r.assign(n,0);
        for(int i=0;i<n;i++) p[i]=i;
    }

    int f(int x){
        if(p[x]==x) return x;
        return p[x]=f(p[x]);
    }

    void u(int a,int b){
        a=f(a); b=f(b);
        if(a==b) return;
        if(r[a]<r[b]) p[a]=b;
        else if(r[b]<r[a]) p[b]=a;
        else{ p[b]=a; r[a]++; }
    }
};

class Solution {
public:

    bool ok(int n,vector<vector<int>>&e,int k,ll m){
        DSU d(n);
        int used=0,up=0;

        for(auto &x:e){
            int u=x[0],v=x[1],s=x[2],t=x[3];
            if(t){
                if(s<m) return 0;
                if(d.f(u)==d.f(v)) return 0;

                d.u(u,v);
                used++;
            }
        }

        for(auto &x:e){
            int u=x[0],v=x[1],s=x[2],t=x[3];
            if(!t && s>=m){
                if(d.f(u)!=d.f(v)){
                    d.u(u,v);
                    used++;
                }
            }
        }

        for(auto &x:e){
            int u=x[0],v=x[1],s=x[2],t=x[3];
            if(!t && s<m && 2LL*s>=m && up<k){
                if(d.f(u)!=d.f(v)){
                    d.u(u,v);

                    used++;
                    up++;
                }
            }
        }

        return (used==n-1);
    }

    int maxStability(int n,vector<vector<int>>& e,int k){ 
        ll l=0,h=2E9,ans=-1;

        while(l<=h){
            ll m=(l+h)>>1;
            if(ok(n,e,k,m)){
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }

        return ans;
    }
};