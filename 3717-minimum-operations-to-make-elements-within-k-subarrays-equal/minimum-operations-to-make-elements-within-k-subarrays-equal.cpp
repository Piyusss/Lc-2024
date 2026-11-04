using ll=long long;

struct FenwickTree {
    int n;
    vector<ll>t;

    FenwickTree(int n):n(n),t(n+1){}

    void add(int i,ll x){
        for(i++;i<=n;i+=i&-i) t[i]+=x;
    }

    ll sum(int i){
        ll s=0;
        for(i++;i>0;i-=i&-i) s+=t[i];
        return s;
    }

    int lower_bound(ll x){
        ll p=0,s=0;

        for(int i=1<<__lg(n);i;i>>=1){
            if(p+i<=n&&s+t[p+i]<x){
                s+=t[p+i];
                p+=i;
            }
        }

        return p;
    }
};

class Solution {
public:
    ll minOperations(vector<int>& a,int x,int k) {
        int n=a.size();

        vector<pair<int,int>>v;
        for(int i=0;i<n;i++) v.push_back({a[i],i});

        sort(v.begin(),v.end());
        vector<int>p(n);

        for(int i=0;i<n;i++) p[v[i].second]=i;
        vector<vector<ll>>d(n,vector<ll>(k+1,1e15));

        FenwickTree c(n),f(n);
        int h=(x+1)/2,z=x-h;

        for(int i=0;i<n;i++){
            c.add(p[i],1);
            f.add(p[i],a[i]);

            if(i-x+1<0) continue;

            if(i-x+1>0){
                c.add(p[i-x],-1);
                f.add(p[i-x],-a[i-x]);
            }

            int j=c.lower_bound(h);
            ll m=v[j].first;

            ll cur=1LL*h*m-f.sum(j)+f.sum(n-1)-f.sum(j)-1LL*z*m;

            if(i>0) d[i][1]=d[i-1][1];
            d[i][1]=min(d[i][1],cur);

            if(i-x<0) continue;

            for(int j=2;j<=k;j++){
                d[i][j]=d[i-1][j];
                d[i][j]=min(d[i][j],d[i-x][j-1]+cur);
            }
        }

        return d[n-1][k];
    }
};